//
//  AppDelegate.h
//  beacon_test
//
//  Created by JoeJoe on 2016/4/6.
//  Copyright © 2016年 JoeJoe. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <BeaconFramework/BeaconFramework.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, strong) Notification *notification;
@property (nonatomic, strong) IIIBeacon *iiibeacon;
@property (nonatomic, strong) message *msg;
@property (nonatomic, strong) BeaconInfo *beacon_info;

@property (nonatomic, strong) IIIBeaconDetection *detection;
@property (nonatomic, strong) Manager *manager;
@property (nonatomic, strong) NSMutableArray *message_list;

@property  NSTimer *timer;


@end

