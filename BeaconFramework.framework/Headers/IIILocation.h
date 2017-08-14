//
//  IIILocation.h
//  BeaconFramework
//
//  Created by JoeJoe on 2017/5/4.
//  Copyright © 2016年 Joe. All rights reserved.
//

#ifndef IIILocation_h
#define IIILocation_h


#endif /* IIILocation_h */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class LocationInfo;
@class iiiLocation;
@interface IIILocation : NSObject{
    
}
- (void)get_locations_withkey:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(LocationInfo * _Nonnull, BOOL))completion;
- (void)get_locations_withkey_security:(NSString * _Nonnull)server key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(LocationInfo * _Nonnull, BOOL))completion;
-(void) setLogAccount: (NSString *) account;

@end



@interface LocationInfo : NSObject{
    
}
@property (atomic, strong) NSMutableArray * _Nullable LocationList;
@property (atomic, strong) NSString * _Nullable state;
@property (atomic, strong) NSString * _Nullable server;
@property (atomic, strong) NSString * _Nullable app_key;
@property (atomic, assign) BOOL product_server;

@end


@interface iiiLocation : NSObject

@property (atomic, strong) NSNumber * _Nullable location_id;
@property (atomic, strong) NSString * _Nullable location_name;
@property (atomic, strong) NSString * _Nullable latitude;
@property (atomic, strong) NSString * _Nullable longitude;
@property (atomic, strong) NSNumber * _Nullable radius;
@property (atomic, strong) CLLocation * _Nullable clocation;

@end


extern NSString *ldevice_id;
extern NSString *ldevice_account;


extern NSString *location_sdk_version;
extern NSString *location_sdk_release_time;



