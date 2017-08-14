//
//  AppDelegate.m
//  beacon_test
//
//  Created by JoeJoe on 2016/4/6.
//  Copyright © 2016年 JoeJoe. All rights reserved.
//

#import "AppDelegate.h"
//@import BeaconFramework;



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
     _notification = [IIINotification new] ;
    _iiibeacon = [IIIBeacon new];
    //_detection = [IIIBeaconDetection new];
    
    //若你在同一視窗下多次建立 IIIBeaconDetection 卻未正確停止偵測, 系統將會存在多組 IIIBeaconDetection 造成系統效能耗損
    //在主程式中呼叫 Manager 可自動幫助你在使用 [_detection Stop] 時關閉多餘的 IIIBeaconDetection
    //只需呼叫一次！！若無多次建立並或未正確停止之狀況則無需使用
    //_manager = [Manager new];
    
    

    //建立timer用以驗證是否取得資料（資料將會自動傳回至對應變數）
    // _timer = [NSTimer scheduledTimerWithTimeInterval:1 target:self selector:@selector(update) userInfo:nil repeats:YES];
    
    
    //回傳非可識別化資料欄位
    [_iiibeacon set_account_info_security:@"ideas.iiibeacon.net" key:@"app key" name: @"test" age: @"test" sex: @"test" birthyear: @"test" birthmonth: @"test" birthday: @"test" job: @"test" phone: @"test" email: @"test" address: @"test" completion: ^(NSString *message , BOOL Sucess) {
        if (Sucess) {
        }
    }
     
     ];
    
    
    //IIIBeaconDetection
    //Production Environment ( If Test Environment, Please use get_beacons_withkey:@"52.69.184.56" key: @"app key" ... )
    [_iiibeacon get_beacons_withkey_security:@"ideas.iiibeacon.net" key: @"app key" completion: ^(BeaconInfo *item , BOOL Sucess) {
        if (Sucess) {
            //app key對應beacon取得成功
            dispatch_async(dispatch_get_main_queue(), ^{
                
                //Initial Detection
                _detection = [[IIIBeaconDetection alloc] initWithBeacon_data:item];
                
                 //委派 IIIBeaconDetection 給 AppDelegate
                _detection.delegate = self;
                
                
                 //開始偵測
                [_detection Start];
            });
        }
    }
     
     ];
    


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
                

                [_timer invalidate];
                
                break;
            }
        }
        
    }
}

////找到對應Beacon (required!!)
-(void)BeaconDetectd{

    
    
    if (_detection.ActiveBeaconList.count > 0) {
        for (ActiveBeacon* key in [self.detection ActiveBeaconList]) {
            
            BOOL found = NO;
            
            NSPredicate *predicate = [NSPredicate predicateWithFormat:@"uuid == %@", key.id];
            NSArray *filtered = [_message_list filteredArrayUsingPredicate:predicate];
            if ([filtered count] > 0) {
                found = true;
                
            }
            if (!found) {
                
                //建立推播內容物件
                _Message *message_item = [_Message new];
                message_item->msg = [message new];
                message_item->uuid = key.id;

//                //取得Beacon對應推播內容
//                 //Production Environment ( If Test Environment, Please use get_push_message:@"52.69.184.56" .... )
                [_notification get_push_message_security:@"ideas.iiibeacon.net" major: key.major.integerValue minor:key.minor.integerValue key:@"app key" completion:^(message *item, BOOL Sucess){
                    if (Sucess) {
                        //資料回傳成功
                        if (item.content.coupons.count > 0) {
                            NSLog(@"%@", [item.content.coupons[0] photoUrl]);
                        }
                        
                    }
                }];
             
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


