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
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?
    
    //Initial BeaconFramework
    var notification = Notification()
    var iiibeacon = IIIBeacon()
    
    
    //建立Beacon物件
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

