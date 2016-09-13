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
@property (atomic, weak) NSString * _Nullable templateName;
@property (atomic, weak) NSString * _Nullable templateDescription;
@property (atomic, weak) NSString * _Nullable sellerName;
@property (atomic, weak) NSString * _Nullable sellerDescription;
@property (atomic, weak) NSString * _Nullable couponBriefDescription;
@property (atomic, weak) NSString * _Nullable couponDetailDescription;
@property (atomic, weak) NSString * _Nullable others;
@property (atomic, weak) NSNumber * _Nullable quantity;
@property (atomic, weak) NSNumber * _Nullable surplus;
@property (atomic, weak) NSString * _Nullable photoUrl;
@property (atomic, weak) NSString * _Nullable validStartDate;
@property (atomic, weak) NSString * _Nullable validEndDate;
@end


@interface Product : NSObject
@property (atomic, weak) NSString * _Nullable templateName;
@property (atomic, weak) NSString * _Nullable templateDescription;
@property (atomic, weak) NSString * _Nullable sellerName;
@property (atomic, weak) NSString * _Nullable sellerDescription;
@property (atomic, weak) NSString * _Nullable productBriefDescription;
@property (atomic, weak) NSString * _Nullable productDetailDescription;
@property (atomic, weak) NSNumber * _Nullable originPrice;
@property (atomic, weak) NSNumber * _Nullable discount;
@property (atomic, weak) NSString * _Nullable others;
@property (atomic, weak) NSNumber * _Nullable quantity;
@property (atomic, weak) NSNumber * _Nullable surplus;
@property (atomic, weak) NSString * _Nullable photoUrl;
@property (atomic, weak) NSString * _Nullable validStartDate;
@property (atomic, weak) NSString * _Nullable validEndDate;
@end


@interface PushContent : NSObject
@property (atomic, strong) NSMutableArray * _Nonnull coupons;
@property (atomic, strong) NSMutableArray * _Nonnull products;
@end




