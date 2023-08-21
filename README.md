# Electronic Technologies and Biosensors Laboratory

## Academic Year 2021/2022 - II Semester

## Final Project - Project 5 - Sleep position classifier
## Objective
![image](https://user-images.githubusercontent.com/100738621/178038332-7114b885-f36a-4cbb-af34-71ec64025219.png)

The aim of this project was to develop a system able to correctly classify and forecast **12 specific sleep positions** (visible in the image above), using the data from **two accelerometers LIS3DH** placed one on the chest and one on the right ankle. 
The finished project includes: 
- development of the wearable device
- data acquisition
- data processing
- GUI for data sampling and visualization
- machine learning architecture able to perform sleep position classification

The PSoC communicates with the LIS3DH sensors using **I2C communication**, and the accelerometers have a sampling frequency set at 10Hz. 
The communication between the PSoC device and the pc was created using a **HC05 Bluetooth module** to make the device wearable.
Also, for wearability, the device is powered with a **9V battery** and a subsequent **9 to 5 voltage transformer**.
### Hardware
- 2 LIS3DH accelerometers
- 1 HC05 Bluetooth module
- 1 9V battery
- 1 9to5 voltage transformer
- 1 PSoC CY8CKIT-059 
- 1 breadboard
- 2 3D printed casings were used to encapsulate the accelerometers and place them on the body
- 10 2m long cables to connect the accelerometers to the PSoC
- 2 modular velcro bands to fix the accelerometers in place 

The links between the PSoC and the different components can be found in the dedicated folder in the form of the **hardware** **setup** documentation and the eagle schematic and board files.
The casing's 3D model can also be found in the dedicated folder.

### PSoC code
This section of code is responsible for I2C communication between the PSoC and the 2 accelerometers, which are sampling data with an ODR of 10Hz and are set on **FIFO mode**. The following code averages the 32 samples of the FIFO buffer from both accelerometers, each time they are simultaneously full.
Finally, the 6 averaged acceleration values (x, y and z from the chest and the ankle) are combined in a unique string and managed by the **UART** of the bluetooth module, having a baudrate of 9600 bps.

All code files of this section have been individually commented on for clarity.

### GUI code

This section of code deals with establishing a connection between pc and bluetooth module, visualizing the data sampled in real-time, and producing csv files following a specific sampling protocol, which are further used to train the machine learning module. 
It follows a description of the most important subsections of code, but the code has been commented throughout for clarity.
#### $Serial$ $interface$
This subsection is devoted to scanning all serial ports and creating a list used in the dropdown menu.
#### $Serial$ $Worker$
The **SerialWorker** class handles the connection with the bluetooth module by establishing a connection with the desired serial port (selectable in a drop down menu), reading data from this port from start (S) to end (E) tokens as soon as the Start button is pressed, **storing iteratively** the read lines in the data object and saving them at the end of the protocol in a single csv file.  
It's also responsible for sending char data on the serial port and closing the serial port before closing the app.
#### $Graphic$ $interface$ 
This sub-section of code deals with creating the **window** used by all the plot widgets and the various **buttons**. 
It's worth noting that the 6 data charts are plotted on the same window by first removing the oldest point, then adding the new one, and finally updating the data.
#### $Main$
The main is responsible for setting the **window size**, creating the **thread handler** and **initializing** all the **functions** previously mentioned.

### Machine Learning
#### $Install$

The Machine Learning portion of this project was created using a Jupyter Notebook.
The library used are available in the *requirements.txt* file inside the *machine learning folder* and any function needed is clearly listed and commented troughout the code.

#### $Data$
In order to run the code, it's necessary to upload the csv files produced by us during the sampling. All the paths are stored in a distinct variable.

The data consists in 11 csv files sampled from 11 different people, it's worth nothing that the file 'fabio_20220601_193018.csv' was discarted 
due to errors during the sampling procedure, thus we ended up with 10 different people, a sample size big enough to guarantee inter-subject variabilty.

The data available was studied in three different ways, in order to see if the accuracy of the model could be improved:
- **Raw** sampled data
- **Average** of data for each sensor
- **Average** of data for each sensor + **minimun and maximum** values for each sensor

#### $Data Preprocessing$
It's important to note that the **first 20 samples of each position recording were removed**, due to the patient still not being completely settled down and ready for the sampling. 
The data was also **normalized** as good practice dictates.

#### $Data Visualization$
The data was visualized multiple times, this allowed us to purge it from artifacts and anomalies and improve the learning algorithm, such as the *transient
data* between two positions mentioned in the previous paragraph.

#### $Features$
The data was gathered from 2 accelerometers, one on the chest and one on the right ankle. Therefore we have 6 inputs + 1 input for the subject's sex.
- x_chest
- y_chest
- z_chest
- x_ankle
- y_ankle
- z_ankle
- sex

#### $Target Variable$
The variable that we need to predict is the sleeping position. It can be one of twelve positions.

##### $Run$
To run the code, simply run sequentially every data cell. 
The code was tested on all three datasets, and the best performing one turned out to be the **Random Forest Classifier** learned using the **average+min_max** dataset, which reached **50% of accuracy** on the test set.

#### $Master Position$
In order to better assess the performance of the classifier we also tested it only on the four "master" positions: by grouping by three the positions (and therefore eliminating the small variations between each of the main positions) we obtained the **main positions**: supine, prone, left-sided and right-sided. 
When we tested our algorithm only with these targets, we easily obtained **100% accuracy**.
