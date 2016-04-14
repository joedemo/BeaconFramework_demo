//
//  AppDelegate.m
//  beacon_test
//
//  Created by JoeJoe on 2016/4/6.
//  Copyright © 2016年 JoeJoe. All rights reserved.
//

#import "AppDelegate.h"
@import BeaconFramework;



@interface AppDelegate ()

@end


@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
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
    [_notification get_push_message:@"server ip" major:777 minor:404 key:@"app key" msg:_msg];
    
    //建立timer用以驗證是否取得資料（資料將會自動傳回至對應變數）
     _timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(update) userInfo:nil repeats:YES];
    
    return YES;
}

//驗證資料
- (void) update
{
    
    if ( [_msg.state  isEqual: @"Sucess" ] && [_beacon_info.state isEqual:  @"Sucess"] ) {
        
    
        NSLog(@"已取得資料");
        _timer.invalidate;
    }
}







- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end


