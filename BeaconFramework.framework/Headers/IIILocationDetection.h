//
//  IIILocationDetection.h
//  BeaconFramework
//
//  Created by JoeJoe on 2017/4/25.
//  Copyright © 2017年 Joe. All rights reserved.
//

#ifndef IIILocationDetection_h
#define IIILocationDetection_h


#endif /* IIILocationDetection_h */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol IIILocationDetectionDelegate<NSObject>

@required
-(void) LocationDetectd;

@end


@interface ActiveLocation : NSObject
@property (atomic, strong) NSString * _Nullable location_id;
@property (atomic, strong) NSString * _Nullable location_name;
//@property (atomic, strong) NSNumber * _Nullable latitude;
//@property (atomic, strong) NSNumber * _Nullable longitude;
@property (atomic, strong) NSNumber * _Nullable radius;
@property (atomic, strong) CLLocation * _Nullable location;
@end

@class LocationInfo;
@interface IIILocationDetection : NSObject


@property (atomic, weak) id <IIILocationDetectionDelegate> _Nullable delegate;
@property (nonatomic, strong) NSMutableArray * _Nullable ActiveLocationList;
@property (nonatomic, strong) NSMutableArray * _Nullable HistoryLocationList;
@property (strong, atomic) CLLocationManager * _Nullable locationManager;
@property (assign, nonatomic) NSInteger locationRequestUpdating;
@property (assign, nonatomic) NSInteger locationRequestSignificant;
@property (atomic, retain) dispatch_queue_t locationQueue;
@property (atomic, retain) dispatch_queue_t significantQueue;

- (nonnull instancetype)initWithLocation_data:(LocationInfo * _Nonnull)location_data;
- (void)Start;


@end
