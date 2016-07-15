# iOS Beacon Notification SDK
III Beacon Detect and Notification Information

##Installation
Import the BeaconFramework.framework file

####Object-C:
#####
Add the BeaconFramework.framework file to xcode project

##Examples
####Object-C:
   Please Check out the sample code
    

##Requirements
- Xcode 7.3 or higher
- iOS 7.0 or higher

##Demo
####Swift:
- IIIBeaconDetect branch

  Build and run the BeaconFramework_demo.xcodeproj in Xcode

####Object-C:
- IIIBeaconDetect(object-c) branch

  Build and run the BeaconFramework_demo(object-c) in Xcode

####IIIBeaconDetect(iOS7.0):
- IIIBeaconDetect(object-c) branch

  Build and run the BeaconFramework_demo(object-c) in Xcode


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
