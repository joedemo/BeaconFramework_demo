//
//  Global.h
//  BeaconFramework
//
//  Created by JoeJoe on 2016/7/7.
//  Copyright © 2016年 Joe. All rights reserved.
//

#ifndef Global_h
#define Global_h


#endif /* Global_h */


@class PushContent;
@interface Coupon : NSObject
@property (nonatomic, copy) NSString * _Nullable sellerName;
@property (nonatomic, copy) NSString * _Nullable sellerDescription;
@property (nonatomic, copy) NSString * _Nullable couponBriefDescription;
@property (nonatomic, copy) NSString * _Nullable couponDetailDescription;
@property (nonatomic, copy) NSString * _Nullable others;
@property (nonatomic, strong) NSNumber * _Nullable quantity;
@property (nonatomic, strong) NSNumber * _Nullable surplus;
@property (nonatomic, copy) NSString * _Nullable photoUrl;
@property (nonatomic, copy) NSString * _Nullable validStartDate;
@property (nonatomic, copy) NSString * _Nullable validEndDate;
@end


@interface Product : NSObject
@property (nonatomic, copy) NSString * _Nullable sellerName;
@property (nonatomic, copy) NSString * _Nullable sellerDescription;
@property (nonatomic, copy) NSString * _Nullable productBriefDescription;
@property (nonatomic, copy) NSString * _Nullable productDetailDescription;
@property (nonatomic, strong) NSNumber * _Nullable originPrice;
@property (nonatomic, strong) NSNumber * _Nullable discount;
@property (nonatomic, copy) NSString * _Nullable others;
@property (nonatomic, strong) NSNumber * _Nullable quantity;
@property (nonatomic, strong) NSNumber * _Nullable surplus;
@property (nonatomic, copy) NSString * _Nullable photoUrl;
@property (nonatomic, copy) NSString * _Nullable validStartDate;
@property (nonatomic, copy) NSString * _Nullable validEndDate;
@end


@interface PushContent : NSObject
@property (nonatomic, retain) NSMutableArray * _Nonnull coupons;
@property (nonatomic, retain) NSMutableArray * _Nonnull products;
@end