//
//  IIINotification.h
//  BeaconFramework
//
//  Created by JoeJoe on 2016/6/20.
//  Copyright © 2016年 Joe. All rights reserved.
//

#ifndef IIINotification_h
#define IIINotification_h


#endif /* IIINotification_h */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "Global.h"


@interface message : NSObject
@property (atomic, strong) PushContent * _Nullable content;
@property (atomic, strong) NSString * _Nullable state;
- (nonnull instancetype)init;
@end



@interface IIINotification : NSObject
- (nonnull instancetype)init;
- (void)get_push_message:(NSString * _Nonnull)server_ip major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message:(NSString * _Nonnull)server_ip major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message:(NSString * _Nonnull)server_ip beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message:(NSString * _Nonnull)server_ip beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message:(NSString * _Nonnull)server_ip location_id:(NSString * _Nonnull)location_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;

- (void)get_push_message_security:(NSString * _Nonnull)security_server major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message_security:(NSString * _Nonnull)security_server major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message_security:(NSString * _Nonnull)security_server beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message_security:(NSString * _Nonnull)security_server beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message_security:(NSString * _Nonnull)security_server location_id:(NSString * _Nonnull)location_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
@end










