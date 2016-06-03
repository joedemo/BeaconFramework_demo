//
//  AppDelegate.m
//  beacon_test
//
//  Created by JoeJoe on 2016/4/6.
//  Copyright © 2016年 JoeJoe. All rights reserved.
//

#import "AppDelegate.h"
@import BeaconFramework;



@interface AppDelegate ()<IIIBeaconDetectionDelegate>

@end

//建立推播內容清單資料結構
@interface _Message: NSObject
{
  @public
    message *msg;
    NSString *uuid;
}
@end
@implementation _Message

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    //Initial BeaconFramework
     _notification = [Notification new] ;

    //建立timer用以驗證是否取得資料（資料將會自動傳回至對應變數）
     _timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(update) userInfo:nil repeats:YES];
    
    _detection = [[IIIBeaconDetection alloc] initWithServer_ip:@"52.69.184.56" key:@"c76294a01287f20adca29c36d964d609133ccbee"];
    _detection.delegate = self;
    
    [_detection Start];
    
    _message_list = [NSMutableArray new];
    
    
    
    return YES;
}

//驗證資料
- (void) update
{
    
    if(_message_list.count > 0 )
    {
        
        for (_Message *item in _message_list) {
            if ([item->msg.state isEqual: @"Sucess"]) {
                
                NSString *result =  [NSString stringWithFormat:@"%@%@%@", @"已取得 ", item->uuid, @" 資料"];
                NSLog(@"%@",result);
                [_timer invalidate];
                
                break;
            }
        }
        
    }
}

////找到對應Beacon (required!!)
-(void)BeaconDetectd{
    if (_detection.ActiveBeaconList.count > 0) {
        for (ActiveBeacon* key in _detection.ActiveBeaconList) {
            
            BOOL found = NO;
            for (_Message *item in _message_list) {
                if ([item->uuid isEqualToString:key.uuid]) {
                    found = YES;
                }
            }
           
            if (!found) {
                
                //建立推播內容物件
                _Message *message_item = [_Message new];
                message_item->msg = [message new];
                message_item->uuid = key.uuid;
            
                //value.message = Notification.message()
                //value.uuid = item.uuid
            
                //取得Beacon對應推播內容
                [_notification get_push_message:@"52.69.184.56" major:key.major.intValue minor:key.minor.intValue key:@"c76294a01287f20adca29c36d964d609133ccbee" msg:message_item->msg];
               [_message_list addObject:message_item];
            
            
            }
        }
        
        
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


