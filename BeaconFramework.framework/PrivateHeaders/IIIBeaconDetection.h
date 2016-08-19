//
//  IIIBeaconDetection.h
//  BeaconFramework
//
//  Created by JoeJoe on 2016/6/20.
//  Copyright © 2016年 Joe. All rights reserved.
//

#ifndef IIIBeaconDetection_h
#define IIIBeaconDetection_h


#endif /* IIIBeaconDetection_h */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

//@interface IIIBeaconDetection : NSObject{
//    //message *msg;
//}
//
//@end

@protocol IIIBeaconDetectionDelegate<NSObject>

@required
-(void) BeaconDetectd;

@end

@interface ActiveBeacon : NSObject
@property (atomic, weak) NSString * _Nullable id;
@property (atomic, weak) NSString * _Nullable uuid;
@property (atomic, weak) NSString * _Nullable major;
@property (atomic, weak) NSString * _Nullable minor;
@property (atomic, strong) NSNumber * _Nullable distance;
@end

@interface EncryptUUID : NSObject
@property (atomic, weak) NSString * _Nullable uuid;
@property (atomic, weak) NSString * _Nullable key;
@end

@class BeaconInfo;
@interface IIIBeaconDetection : NSObject <CLLocationManagerDelegate>

@property (atomic, weak) id <IIIBeaconDetectionDelegate> _Nullable delegate;
@property (atomic, strong) NSMutableArray * _Nullable ActiveBeaconList;
@property (atomic, strong) NSMutableArray * _Nullable HistoryBeaconList;
//@property (nonatomic, retain) NSMutableArray * _Nullable uuid_list;
@property (atomic, strong) NSMutableArray * _Nullable region_list;
@property (atomic) NSInteger BeaconCountFrequency;
@property (atomic) NSInteger Hold_time;
@property (atomic) NSInteger BeaconLogtime;
@property (atomic, copy) NSString * _Nullable Status;
@property (strong, atomic) CLLocationManager * _Nullable locationManager;
@property (atomic, retain) dispatch_queue_t detectQueue;

//- (nonnull instancetype)init ;
//- (nonnull instancetype)initWithServer_ip:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key;
//- (nonnull instancetype)initWithSecurity_server:(NSString * _Nonnull)security_server key:(NSString * _Nonnull)key;
- (nonnull instancetype)initWithBeacon_data:(BeaconInfo * _Nonnull)beacon_data;

- (void)Start;
- (void)Start:(NSString * _Nonnull)proximity_uuid;
- (void)Stop;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didRangeBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons inRegion:(CLBeaconRegion * _Nonnull)region;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didEnterRegion:(CLRegion * _Nonnull)region;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didExitRegion:(CLRegion * _Nonnull)region;
@end

