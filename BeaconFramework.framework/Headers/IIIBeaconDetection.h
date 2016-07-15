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
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic, copy) NSString * _Nullable uuid;
@property (nonatomic, copy) NSString * _Nullable major;
@property (nonatomic, copy) NSString * _Nullable minor;
@property (nonatomic, strong) NSNumber * _Nullable distance;
@end

@interface EncryptUUID : NSObject
@property (nonatomic, copy) NSString * _Nullable uuid;
@property (nonatomic, copy) NSString * _Nullable key;
@end

@class BeaconInfo;
@interface IIIBeaconDetection : NSObject <CLLocationManagerDelegate>

@property (nonatomic, strong) id <IIIBeaconDetectionDelegate> _Nullable delegate;
@property (nonatomic, retain) NSMutableArray * _Nullable ActiveBeaconList;
@property (nonatomic, retain) NSMutableArray * _Nullable HistoryBeaconList;
//@property (nonatomic, retain) NSMutableArray * _Nullable uuid_list;
@property (nonatomic, retain) NSMutableArray * _Nullable region_list;
@property (nonatomic) NSInteger BeaconCountFrequency;
@property (nonatomic) NSInteger Hold_time;
@property (nonatomic) NSInteger BeaconLogtime;
@property (nonatomic, copy) NSString * _Nullable Status;
@property (strong, nonatomic) CLLocationManager * _Nullable locationManager;

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

