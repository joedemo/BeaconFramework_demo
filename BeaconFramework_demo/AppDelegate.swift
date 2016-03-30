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
    
    var notification = Notification()
    var iiibeacon = IIIBeacon()


    func application(application: UIApplication, didFinishLaunchingWithOptions launchOptions: [NSObject: AnyObject]?) -> Bool {
        // Override point for customization after application launch.
        var timer = NSTimer.scheduledTimerWithTimeInterval(1, target: self, selector: Selector("update:"), userInfo: nil, repeats: true)
        
        notification.get_push_message("54.64.237.112", major: 777, minor: 404, key: "0e74aa531e11166ca99e61545152d37cbf194f93", msg: _message)
        
        //var beacon_list: bc.bea
        
        iiibeacon.get_beacons_withkey("54.64.237.112", key: "0e74aa531e11166ca99e61545152d37cbf194f93", beacon_info: _beacon_info)
        

        return true
    }
    
    func update(timer: NSTimer) {
        
        if(_message.state == "Sucess")
        {
            print("done")
        }
        
        if(_beacon_info.state == "Sucess")
        {
            print("done")
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

