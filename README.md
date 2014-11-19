<h1>SEMESTER ASSIGNMENT PART C</h1>
Submission deadline: December 17 2014

<h2>Objectives</h2>
This assignment will be performed and handed in as a piece of individual work.  It will determine 45% of the final grade in the course.  

A soft sensor based on data mining and data fusion shall be created. The basic approach should apply a regular FF-BP Neural Network at its core.  Additional techniques for pre- and post-processing are recommended, but not required.  Ideas from Big Data and Deep Learning neural networks can also be applied. For this the student must explore the literature on his/her own.

<h2>Basic sensor rig</h2>
Input should be based on Tiny Mesh’s  data mesh concept. Time series from dedicated sensors,  including audio, light, temperature, CO2, motion and humidity are produced with one minute resolution.  These shall be analyzed and processed for both detection, classification and prediction.
 

The data can be downloaded from the Tiny Mesh cloud.

The student must define its own training and test method. Several modes should be included. The method chosen must involve controlled experiments and monitoring of actions in the room where the sensor is mounted.  To create a training and test set there must be ample empiric material gathered in the form of time series. Time series must be tagged or aligned chronologically with the obsrvations made in the room. Such tags would typically be “room not in use”, “room used by one person”, “room used by two persons” etc. This suggests a controlled method of observation that must be combined with the sensor samples gathered.  The type and form of such observations will demand space in the input vector. 

The NN model should be able to classify the use of the room and yield output on the form:
<li>“Room not in use”</li>
<li>“Room used by one person only”</li>
<li>“Room used by at least one person”</li>
<li>“Room used by at least two persons”</li>
<li>“Room used by at least five persons”</li>
<li>“Room used by a full class”</li>

Other ancillary modes could be added i.e. 
<li>“Indoor climate is poor”</li>
<li>“Window is open”</li>
<li>“Window is closed”</li>

An additional feature with the NN would be to predict the use of and the number of people being present on a given hour during the week.

The neural network should be demonstrated and presented in Week 49.  More information on the demo will be given on Its Learning later. 

A presentation of app. 12-15 slides should present the:
1. The objectives and constraints related to the project
2. What the NN is supposed to do
3. The method of approach selected, including description of supportive techniques
4. Training and test set creation
5. NN architecture and its justification
6. Results obtained and performance of NN built
7. Explanation of the results
8. Recommendations for improvement

After feedback from teacher the student will be able to adjust and conclude after week 49. Final delivery will be December 17. Method of delivery will be presented later.