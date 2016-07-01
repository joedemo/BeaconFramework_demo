//
//  AppDelegate.swift
//  BeaconFramework_demo
//
//  Created by JoeJoe on 2016/3/30.
//  Copyright © 2016年 JoeJoe. All rights reserved.
//

import UIKit
import BeaconFramework

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, IIIBeaconDetectionDelegate {

    var window: UIWindow?
    
    //Initial BeaconFramework
    var notification = Notification()
    var detection = IIIBeaconDetection()
    var iiibeacon = IIIBeacon()
    
    //建立推播內容物件列表
    var message_list: [_Message] = []
    
    //建立推播內容物件
    var _message:Notification.message = Notification.message()
   
    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        
        //Production Environment ( If Test Environment, Please use get_beacons_withkey("52.69.184.56", key: "app key", .....) )
        iiibeacon.get_beacons_withkey_security("ideas.iiibeacon.net", key: "app key", completion: { (beacon_info: IIIBeacon.BeaconInfo, Sucess: Bool) in
            if(Sucess){
                dispatch_async(dispatch_get_main_queue(),{
                    
                    //Initial Detection
                    self.detection = IIIBeaconDetection(beacon_data: beacon_info)
                    
                    //委派 IIIBeaconDetection 給 AppDelegate
                    self.detection.delegate  = self
                    
                    //開始偵測
                    self.detection.Start()
                    
                })            }
            }
        )
        

        //建立timer用以驗證是否取得資料（資料將會自動傳回至對應變數）
        //NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: #selector(AppDelegate.update(_:)), userInfo: nil, repeats: true)
        
        return true
    }
    
    //驗證資料
//    func update(timer: NSTimer) {
//        
//        if(message_list.count > 0 )
//        {
//            
//            if let item = message_list.filter({$0.message!.state == "Sucess"}).first {
//                
//                print("已取得 " + item.uuid! + " 資料")
//                timer.invalidate()
//                
//            }
//            
//        }
//        
//        
//    }
    
    //找到對應Beacon (required!!)
    func BeaconDetectd() {
        if detection.ActiveBeaconList?.count > 0 {
            
            for item in detection.ActiveBeaconList! {
                    
                    if !message_list.contains({$0.uuid == item.uuid}) {
                        
                        let value = _Message()
                        //建立推播內容物件
                        value.message = Notification.message()
                        value.uuid = item.uuid
                        
                        //取得Beacon對應推播內容
                        ////Production Environment ( If Test Environment, Please use get_push_message("52.69.184.56", ....) )
                        notification.get_push_message_security("ideas.iiibeacon.net", major: Int(item.major!)!, minor: Int(item.minor!)!, key: "app key" ){ (completion) -> () in
                            
                            if(completion.Sucess){
                                
                                //資料回傳成功
                                print("已取得 " + item.uuid! + " 資料; photoUrl: " + completion.msg.content!.coupons[0].photoUrl!)
                            }
                        }
                        
                        
                        message_list.append(value)
                    }
                
            }
            
        }
    }
    
    //建立推播內容清單資料結構
    class _Message {
        //推播內容物件
        var message: Notification.message?
        var uuid: String?
    }

    func applicationWillResignActive(application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

