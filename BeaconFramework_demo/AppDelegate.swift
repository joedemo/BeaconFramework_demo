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
class AppDelegate: UIResponder, UIApplicationDelegate, IIIBeaconDetectionDelegate, IIILocationDetectionDelegate {

    var window: UIWindow?
    
    //Initial BeaconFramework
    var notification = BeaconFramework.IIINotification()
    var detection = IIIBeaconDetection()
    var location_detection = IIILocationDetection()
    
    var iiibeacon = IIIBeacon()
    var iiilocation = IIILocation()
    
    //建立推播內容物件列表
    var message_list: [_Message] = []
    
    //建立推播內容物件
    var _message:BeaconFramework.IIINotification.message = BeaconFramework.IIINotification.message()
   
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        
        iiibeacon.setAccountInfo(server: "ideas.iiibeacon.net", key: "app key", name: "test", age: "test", sex: "test", birthyear: "test", birthmonth: "test", birthday: "test", job: "test", phone: "test", email: "1@1", address: "test", completion: { (message: String, Success: Bool) in
            if Success {
                print(message)
            }
        }
        )
        
        
        //Production Environment ( If Test Environment, Please use get_beacons_withkey("52.69.184.56", key: "app key", .....) )
        iiibeacon.get_beacons_withkey_security(server: "ideas.iiibeacon.net", key: "app key", completion: { (beacon_info: IIIBeacon.BeaconInfo, Sucess: Bool) in
            if(Sucess){
                DispatchQueue.main.async(execute: {
                    
                    //Initial Detection
                    self.detection = IIIBeaconDetection(beacon_data: beacon_info)
                    
                    //委派 IIIBeaconDetection 給 AppDelegate
                    self.detection.delegate  = self
                    
                    //開始偵測
                    self.detection.Start()
                    
                })            }
            }
        )
        
        iiilocation.get_locations_withkey_security(server: "ideas.iiibeacon.net", key: "app key", completion: { (location_info: IIILocation.LocationInfo, Sucess: Bool) in
            if(Sucess){
                DispatchQueue.main.async(execute: {
                    
                    //Initial Detection
                    self.location_detection = IIILocationDetection(location_data: location_info)
                    
                    //委派 IIILocationDetection 給 AppDelegate
                    self.location_detection.delegate  = self
                    
                    //開始偵測
                    self.location_detection.Start()
                    
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
        if (detection.ActiveBeaconList?.count)! > 0 {
            
            for item in detection.ActiveBeaconList! {
                    
                    if !message_list.contains(where: {$0.uuid == item.id}) {
                        
                        let value = _Message()
                        //建立推播內容物件
                        value.message = BeaconFramework.IIINotification.message()
                        value.uuid = item.id
                    
                        //取得Beacon對應推播內容
                        ////Production Environment ( If Test Environment, Please use get_push_message("52.69.184.56", ....) )
                        notification.get_push_message_security(security_server: "ideas.iiibeacon.net", major: Int(item.major!)!, minor: Int(item.minor!)!, key: "app key" ){ (completion) -> () in
                            
                            if(completion.1){
                                
                                //資料回傳成功
                                if completion.0.content!.products.count > 0{
                                 print("已取得 " + item.id! + " 資料; photoUrl: " + completion.0.content!.products[0].photoUrl!)
                                }
                               
                            }
                        }
                        
                        
                        message_list.append(value)
                    }
                
            }
            
        }
    }
    
    //找到對應Location (required!!)
    func LocationDetectd() {
        if (location_detection.ActiveLocationList?.count)! > 0 {
            
            for item in location_detection.ActiveLocationList! {
                
                if !message_list.contains(where: {$0.location_id == item.location_id}) {
                    
                    let value = _Message()
                    //建立推播內容物件
                    value.message = BeaconFramework.IIINotification.message()
                    value.location_id = item.location_id
                    
                    //取得Location對應推播內容
                    ////Production Environment ( If Test Environment, Please use get_push_message("52.69.184.56", ....) )
                    notification.get_push_message_security(security_server: "ideas.iiibeacon.net", location_id: item.location_id!, key: "app key" ){ (completion) -> () in
                        
                        if(completion.1){
                            
                            //資料回傳成功
                            if completion.0.content!.products.count > 0{
                                print("已取得 " + item.location_id! + " 資料; photoUrl: " + completion.0.content!.products[0].photoUrl!)
                            }
                            
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
        var message: BeaconFramework.IIINotification.message?
        var uuid: String?
        var location_id: String?
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }


}

