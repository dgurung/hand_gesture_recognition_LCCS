Hand Gesture Recognition using Web Camera
=========================================

A Qt based gui for hand gesture recognition using OpenCV.


Methods used:
--------------
- Skin detection based on Log Chromatic Color space (described in paper [1]).
- Open hand gesture recognition based on K-curvature and Convex Hull method.
- Tracking open hand gesture using Kalman Filter.
- Palm and fist recognition based on Haar classifiers.
- Removal of face based on Haar classifiers. 


Tools and Libraries Required:
--------------------
- Qt
- OpenCV

Usage:
------
Built the project in Qt. Currently the project supports laptop webcamera.


References:
-----------
1. Efficient Skin Detection Under Severe Illumination Changes and Shadows,B. Khanal, D. Sidibe, ICIRA 2011. 
http://link.springer.com/chapter/10.1007%2F978-3-642-25489-5_59
