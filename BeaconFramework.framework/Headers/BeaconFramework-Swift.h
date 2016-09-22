// Generated by Apple Swift version 3.0 (swiftlang-800.0.46.2 clang-800.0.38)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import CoreLocation;
#endif

#import <BeaconFramework/BeaconFramework.h>

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSNumber;

SWIFT_CLASS("_TtC15BeaconFramework12ActiveBeacon")
@interface ActiveBeacon : NSObject
@property (nonatomic, copy) NSString * _Nullable id;
@property (nonatomic, copy) NSString * _Nullable major;
@property (nonatomic, copy) NSString * _Nullable minor;
@property (nonatomic, strong) NSNumber * _Nullable distance;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework6Beacon")
@interface Beacon : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework6Coupon")
@interface Coupon : NSObject
@property (nonatomic, copy) NSString * _Nullable templateName;
@property (nonatomic, copy) NSString * _Nullable templateDescription;
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
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework11EncryptUUID")
@interface EncryptUUID : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class NSURLSession;
@class NSMutableURLRequest;

/**
  The class that does the magic. Is a subclass of NSOperation so you can use it with operation queues or just a good ole HTTP request.
*/
SWIFT_CLASS("_TtC15BeaconFramework4HTTP")
@interface HTTP : NSOperation
/**
  This is for handling authenication
*/
@property (nonatomic, copy) NSURLCredential * _Nullable (^ _Nullable auth)(NSURLAuthenticationChallenge * _Nonnull);
/**
  This is for monitoring progress
*/
@property (nonatomic, copy) void (^ _Nullable progress)(float);
/**
  creates a new HTTP request.
*/
- (nonnull instancetype)init:(NSURLRequest * _Nonnull)req session:(NSURLSession * _Nonnull)session OBJC_DESIGNATED_INITIALIZER;
/**
  Returns if the task is asynchronous or not. NSURLSessionTask requests are asynchronous.
*/
@property (nonatomic, readonly) BOOL isAsynchronous;
@property (nonatomic, readonly) BOOL isReady;
/**
  Returns if the task is current running.
*/
@property (nonatomic, readonly) BOOL isExecuting;
@property (nonatomic, readonly) BOOL isFinished;
/**
  Start the HTTP task. Make sure to set the onFinish closure before calling this to get a response.
*/
- (void)start;
/**
  Cancel the running task
*/
- (void)cancel;
/**
  Sets the task to finished.
  If you aren’t using the DelegateManager, you will have to call this in your delegate’s URLSession:dataTask:didCompleteWithError: method
*/
- (void)finish;
/**
  Check not executing or finished when adding dependencies
*/
- (void)addDependency:(NSOperation * _Nonnull)operation;
/**
  Set the global auth handler
*/
+ (void)globalAuth:(NSURLCredential * _Nullable (^ _Nullable)(NSURLAuthenticationChallenge * _Nonnull))handler;
/**
  Set the global request handler
*/
+ (void)globalRequest:(void (^ _Nullable)(NSMutableURLRequest * _Nonnull))handler;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class BeaconInfo;

SWIFT_CLASS("_TtC15BeaconFramework9IIIBeacon")
@interface IIIBeacon : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)get_beacons_withkeyWithServer_ip:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key beacon_info:(BeaconInfo * _Nonnull)beacon_info;
- (void)get_beacons_withkeyWithServer_ip:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(BeaconInfo * _Nonnull, BOOL))completion;
- (void)get_beacons_withkey_securityWithServer:(NSString * _Nonnull)server key:(NSString * _Nonnull)key beacon_info:(BeaconInfo * _Nonnull)beacon_info;
- (void)get_beacons_withkey_securityWithServer:(NSString * _Nonnull)server key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(BeaconInfo * _Nonnull, BOOL))completion;
- (void)setLogAccountWithAccount:(NSString * _Nonnull)account;
@end


SWIFT_CLASS("_TtCC15BeaconFramework9IIIBeacon10BeaconInfo")
@interface BeaconInfo : NSObject
@property (nonatomic, copy) NSString * _Nullable state;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class CLLocationManager;
@class CLBeacon;
@class CLBeaconRegion;
@class NSMutableArray;
@class CLRegion;
@protocol IIIBeaconDetectionDelegate;

SWIFT_CLASS("_TtC15BeaconFramework18IIIBeaconDetection")
@interface IIIBeaconDetection : NSObject <LBeaconMonitorDelegate, CLLocationManagerDelegate>
@property (nonatomic, weak) id <IIIBeaconDetectionDelegate> _Nullable delegate;
@property (nonatomic, copy) NSArray<ActiveBeacon *> * _Nullable ActiveBeaconList;
@property (nonatomic) NSInteger BeaconCountFrequency;
@property (nonatomic) NSInteger Hold_time;
@property (nonatomic) NSInteger BeaconLogtime;
@property (nonatomic, copy) NSString * _Nullable Status;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithServer_ip:(NSString * _Nonnull)server_ip key:(NSString * _Nonnull)key OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithSecurity_server:(NSString * _Nonnull)security_server key:(NSString * _Nonnull)key OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithBeacon_data:(BeaconInfo * _Nonnull)beacon_data OBJC_DESIGNATED_INITIALIZER;
- (void)Start;
- (void)StartWithProximity_uuid:(NSString * _Nonnull)proximity_uuid;
- (void)Stop;
- (void)locationManager:(CLLocationManager * _Nonnull)manager didRangeBeacons:(NSArray<CLBeacon *> * _Nonnull)beacons inRegion:(CLBeaconRegion * _Nonnull)region;
- (void)lbeaconBeaconsRanged:(NSMutableArray * _Nullable)beacons;
- (void)locationManagerWithManager:(CLLocationManager * _Nonnull)manager didEnterRegion:(CLRegion * _Nonnull)region;
- (void)locationManagerWithManager:(CLLocationManager * _Nonnull)manager didExitRegion:(CLRegion * _Nonnull)region;
@end


SWIFT_PROTOCOL("_TtP15BeaconFramework26IIIBeaconDetectionDelegate_")
@protocol IIIBeaconDetectionDelegate
- (void)BeaconDetectd;
@end

@class message;

SWIFT_CLASS("_TtC15BeaconFramework15IIINotification")
@interface IIINotification : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)get_push_messageWithServer_ip:(NSString * _Nonnull)server_ip major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_messageWithServer_ip:(NSString * _Nonnull)server_ip major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_messageWithServer_ip:(NSString * _Nonnull)server_ip beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_messageWithServer_ip:(NSString * _Nonnull)server_ip beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message_securityWithSecurity_server:(NSString * _Nonnull)security_server major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message_securityWithSecurity_server:(NSString * _Nonnull)security_server major:(NSInteger)major minor:(NSInteger)minor key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
- (void)get_push_message_securityWithSecurity_server:(NSString * _Nonnull)security_server beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key msg:(message * _Nonnull)msg;
- (void)get_push_message_securityWithSecurity_server:(NSString * _Nonnull)security_server beacon_id:(NSString * _Nonnull)beacon_id key:(NSString * _Nonnull)key completion:(void (^ _Nonnull)(message * _Nonnull, BOOL))completion;
@end

@class PushContent;

SWIFT_CLASS("_TtCC15BeaconFramework15IIINotification7message")
@interface message : NSObject
@property (nonatomic, strong) PushContent * _Nullable content;
@property (nonatomic, copy) NSString * _Nullable state;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSLock (SWIFT_EXTENSION(BeaconFramework))
@end


@interface NSMutableURLRequest (SWIFT_EXTENSION(BeaconFramework))
/**
  Convenience init to allow init with a string.
  -parameter urlString: The string representation of a URL to init with.
*/
- (nullable instancetype)initWithUrlString:(NSString * _Nonnull)urlString;
/**
  Check if the request requires the parameters to be appended to the URL
*/
- (BOOL)isURIParam;
/**
  check if the parameters contain a file object within them
  -parameter parameters: The parameters to search through for an upload object
*/
- (BOOL)containsFile:(id _Nonnull)parameters;
@end


@interface NSNumber (SWIFT_EXTENSION(BeaconFramework))
@end


SWIFT_CLASS("_TtC15BeaconFramework7Product")
@interface Product : NSObject
@property (nonatomic, copy) NSString * _Nullable templateName;
@property (nonatomic, copy) NSString * _Nullable templateDescription;
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
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework11PushContent")
@interface PushContent : NSObject
@property (nonatomic, copy) NSArray<Coupon *> * _Nonnull coupons;
@property (nonatomic, copy) NSArray<Product *> * _Nonnull products;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSCoder;

/**
  This is how to upload files in SwiftHTTP. The upload object represents a file to upload by either a data blob or a url (which it reads off disk).
*/
SWIFT_CLASS("_TtC15BeaconFramework6Upload")
@interface Upload : NSObject <NSCoding>
/**
  Reads the data from disk or from memory. Throws an error if no data or file is found.
*/
- (NSData * _Nullable)getDataAndReturnError:(NSError * _Nullable * _Nullable)error;
/**
  Standard NSCoder support
*/
- (void)encodeWithCoder:(NSCoder * _Nonnull)aCoder;
/**
  Required for NSObject support (because of NSCoder, it would be a struct otherwise!)
*/
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder;
/**
  Initializes a new Upload object with a fileUrl. The fileName and mimeType will be infered.
  -parameter fileUrl: The fileUrl is a standard url path to a file.
*/
- (nonnull instancetype)initWithFileUrl:(NSURL * _Nonnull)fileUrl;
/**
  Initializes a new Upload object with a data blob.
  -parameter data: The data is a NSData representation of a file’s data.
  -parameter fileName: The fileName is just that. The file’s name.
  -parameter mimeType: The mimeType is just that. The mime type you would like the file to uploaded as.
  upload a file from a a data blob. Must add a filename and mimeType as that can’t be infered from the data
*/
- (nonnull instancetype)initWithData:(NSData * _Nonnull)data fileName:(NSString * _Nonnull)fileName mimeType:(NSString * _Nonnull)mimeType;
@end


@interface Upload (SWIFT_EXTENSION(BeaconFramework))
@end

#pragma clang diagnostic pop
