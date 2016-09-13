//
//  IIIBeacon.h
//  BeaconFramework
//
//  Created by JoeJoe on 2016/7/7.
//  Copyright © 2016年 Joe. All rights reserved.
//

#ifndef IIIBeacon_h
#define IIIBeacon_h


#endif /* IIIBeacon_h */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class BeaconInfo;
@class Beacon;
@interface IIIBeacon : NSObject{
    
}
- (void)get_beacons_withkey:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(BeaconInfo * _Nonnull, BOOL))completion;
- (void)get_beacons_withkey_security:(NSString * _Nonnull)server key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(BeaconInfo * _Nonnull, BOOL))completion;
-(void) setLogAccount: (NSString *) account;

@end


@interface BeaconInfo : NSObject{

}
@property (atomic, strong) NSMutableArray * _Nullable BeaconList;
@property (atomic, strong) NSString * _Nullable state;
@property (atomic, strong) NSString * _Nullable server;
@property (atomic, strong) NSString * _Nullable app_key;
@property (atomic, assign) BOOL product_server;

@end


@interface Beacon : NSObject

@property (atomic, strong) NSString * _Nullable beacon_id;
@property (atomic, strong) NSString * _Nullable beacon_uuid;
@property (atomic, strong) NSString * _Nullable beacon_proximity_uuid;
@property (atomic, strong) NSNumber * _Nullable major;
@property (atomic, strong) NSNumber * _Nullable minor;

//@property (nonatomic, copy) NSString * _Nullable name;
//@property (nonatomic, copy) NSString * _Nullable address;

//@property (nonatomic, copy) NSNumber * _Nullable latitude;
//@property (nonatomic, copy) NSNumber * _Nullable longitude;
@property (atomic, strong) NSNumber * _Nullable power;

@end

extern NSString *device_id;
extern NSString *device_account;


extern NSString *sdk_version;
extern NSString *sdk_release_time;



