# iOS Beacon Notification SDK
III Beacon Detect and Notification Information

##Installation
Import the BeaconFramework.framework file

####Swift:
#####Setp1:
Add the BeaconFramework.framework file to xcode project

![image](https://raw.githubusercontent.com/joedemo/BeaconFramework_demo/master/BeaconFramework_demo/image1.png)

#####Setp2:
Add the BeaconFramework.framework to Embedded Binaries

![image](https://raw.githubusercontent.com/joedemo/BeaconFramework_demo/master/BeaconFramework_demo/image2.png)

#####Object-C
Same as Swift, But you must set Embedded Content Contains Swift Code to "Yes" in Build Settings

![image](https://raw.githubusercontent.com/joedemo/BeaconFramework_demo/master/BeaconFramework_demo/image3.png)

##Examples
####Object-C:
   Please Check out the sample code    
    

##Requirements
- Xcode 7.3 or higher
- iOS 8.0 or higher

##Demo
####Swift:
- IIIBeaconDetect branch

  Build and run the BeaconFramework_demo.xcodeproj in Xcode

####Object-C:
- IIIBeaconDetect(object-c) branch

  Build and run the BeaconFramework_demo(object-c) in Xcode

####Object-C(iOS7.0):
- IIIBeaconDetect(iOS7.0) branch

  Build and run the IIIBeaconDetect(iOS7.0) in Xcode

##iOS 9 App Transport Security issue

Apple made a radical decision with iOS 9, disabling all unsecured HTTP traffic from iOS apps..
Here’s how to disable this issue. Open Info.plist, and add the following lines~

    <key>NSAppTransportSecurity</key>
	<dict>
		<key>NSAllowsArbitraryLoads</key>
		<true/>
	</dict>

##iOS beacon detect setting

Apparently in iOS 8 SDK, requestAlwaysAuthorization (for background location) or requestWhenInUseAuthorization (location only when foreground) call on CLLocationManager is needed before starting location updates.

There also needs to be NSLocationAlwaysUsageDescription or NSLocationWhenInUseUsageDescription key in Info.plist with a message to be displayed in the prompt. Open Info.plist, and add the following lines~

    <key>NSLocationWhenInUseUsageDescription</key>
	   <string>demo</string>
         <key>NSLocationAlwaysUsageDescription</key>
	        <string>demo</string>


##License
BeaconFramework_demo is available under the Apache v2 License.

Copyright © 2016 Joe III.
