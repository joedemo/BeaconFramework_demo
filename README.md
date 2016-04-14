# iOS Beacon Notification SDK
III Beacon List and Notification Information

##Installation
Import the BeaconFramework.framework file

####Swift:
#####Setp1:
Add the BeaconFramework.framework file to xcode project

![image](https://raw.githubusercontent.com/joehour/BeaconFramework_demo/master/BeaconFramework_demo/image1.png)

#####Setp2:
Add the BeaconFramework.framework to Embedded Binaries

![image](https://raw.githubusercontent.com/joehour/BeaconFramework_demo/master/BeaconFramework_demo/image2.png)

#####Object-C
Same as Swift, But you must set Embedded Content Contains Swift Code to "Yes" in Build Settings

![image](https://raw.githubusercontent.com/joehour/BeaconFramework_demo/master/BeaconFramework_demo/image3.png)

##Examples
####Swift:

    
    //Initial BeaconFramework
    var notification = Notification()
    var iiibeacon = IIIBeacon()
    
    
    //建立Beacon內容物件
    var _beacon_info:IIIBeacon.BeaconInfo = IIIBeacon.BeaconInfo()

    
    //建立推播內容物件
    var _message:Notification.message = Notification.message()
   
    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        

        //取得對應Beacon清單
        iiibeacon.get_beacons_withkey("server ip", key: "app key", beacon_info: _beacon_info)
        
        //取得Beacon對應推播內容
        notification.get_push_message("server ip", major: 99999, minor: 99999, key: "app key", msg: _message)
        
        
        //建立timer用以驗證是否取得資料（資料將會自動傳回至對應變數）
        NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("update:"), userInfo: nil, repeats: true)
        

        return true
    }
    
    //驗證資料
    func update(timer: NSTimer) {
        
        if(_message.state == "Sucess" && _beacon_info.state == "Sucess")
        {
            print("已取得資料")
            timer.invalidate()
            
        }
        
        
    }
    

####Object-C:

    //Initial BeaconFramework
    _notification = [Notification new] ;
    _iiibeacon = [IIIBeacon new];
    
    //建立推播內容物件
    _msg = [message new] ;
    
    //建立Beacon內容物件
    _beacon_info = [BeaconInfo new] ;
    
    
    //取得對應Beacon清單
    [_iiibeacon get_beacons_withkey:@"server ip" key: @"app key" beacon_info: _beacon_info];
    
    //取得Beacon對應推播內容
    [_notification get_push_message:@"server ip" major:999999 minor:999999 key:@"app key" msg:_msg];
    

##Requirements
- Xcode 7.2 or higher
- iOS 8.0 or higher

##Demo
####Swift:
- master branch

  Build and run the BeaconFramework_demo.xcodeproj in Xcode

####Object-C:
- Object-C branch

  Build and run the BeaconFramework_demo(object-c).xcodeproj in Xcode

##License
BeaconFramework_demo is available under the Apache v2 License.

Copyright © 2016 Joe III.
