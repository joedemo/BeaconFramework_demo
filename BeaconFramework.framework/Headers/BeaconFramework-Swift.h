// Generated by Apple Swift version 2.1.1 (swiftlang-700.1.101.15 clang-700.1.81)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
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
#endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

SWIFT_CLASS("_TtC15BeaconFramework6Beacon")
@interface Beacon : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSNumber;

SWIFT_CLASS("_TtC15BeaconFramework6Coupon")
@interface Coupon : NSObject
@property (nonatomic, copy) NSString * __nullable sellerName;
@property (nonatomic, copy) NSString * __nullable sellerDescription;
@property (nonatomic, copy) NSString * __nullable couponBriefDescription;
@property (nonatomic, copy) NSString * __nullable couponDetailDescription;
@property (nonatomic, copy) NSString * __nullable others;
@property (nonatomic, strong) NSNumber * __nullable quantity;
@property (nonatomic, strong) NSNumber * __nullable surplus;
@property (nonatomic, copy) NSString * __nullable photoUrl;
@property (nonatomic, copy) NSString * __nullable validStartDate;
@property (nonatomic, copy) NSString * __nullable validEndDate;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class NSURLRequest;
@class NSURLSession;
@class NSMutableURLRequest;


/// The class that does the magic. Is a subclass of NSOperation so you can use it with operation queues or just a good ole HTTP request.
SWIFT_CLASS("_TtC15BeaconFramework4HTTP")
@interface HTTP : NSOperation

/// This is for handling authenication
@property (nonatomic, copy) NSURLCredential * __nullable (^ __nullable auth)(NSURLAuthenticationChallenge * __nonnull);

/// This is for monitoring progress
@property (nonatomic, copy) void (^ __nullable progress)(float);

/// creates a new HTTP request.
- (nonnull instancetype)init:(NSURLRequest * __nonnull)req session:(NSURLSession * __nonnull)session OBJC_DESIGNATED_INITIALIZER;

/// Returns if the task is asynchronous or not. NSURLSessionTask requests are asynchronous.
@property (nonatomic, readonly, getter=isAsynchronous) BOOL asynchronous;
@property (nonatomic, readonly, getter=isReady) BOOL ready;

/// Returns if the task is current running.
@property (nonatomic, readonly, getter=isExecuting) BOOL executing;
@property (nonatomic, readonly, getter=isFinished) BOOL finished;

/// Start the HTTP task. Make sure to set the onFinish closure before calling this to get a response.
- (void)start;

/// Cancel the running task
- (void)cancel;

/// Sets the task to finished. If you aren't using the DelegateManager, you will have to call this in your delegate's URLSession:dataTask:didCompleteWithError: method
- (void)finish;

/// Check not executing or finished when adding dependencies
- (void)addDependency:(NSOperation * __nonnull)operation;

/// Set the global auth handler
+ (void)globalAuth:(NSURLCredential * __nullable (^ __nullable)(NSURLAuthenticationChallenge * __nonnull))handler;

/// Set the global request handler
+ (void)globalRequest:(void (^ __nullable)(NSMutableURLRequest * __nonnull))handler;
@end

@class BeaconInfo;

SWIFT_CLASS("_TtC15BeaconFramework9IIIBeacon")
@interface IIIBeacon : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)get_beacons_withkey:(NSString * __nonnull)server_ip key:(NSString * __nonnull)key beacon_info:(BeaconInfo * __nonnull)beacon_info;
@end


SWIFT_CLASS("_TtCC15BeaconFramework9IIIBeacon10BeaconInfo")
@interface BeaconInfo : NSObject
@property (nonatomic, copy) NSArray<Beacon *> * __nullable BeaconList;
@property (nonatomic, copy) NSString * __nullable state;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSLock (SWIFT_EXTENSION(BeaconFramework))
@end


@interface NSMutableURLRequest (SWIFT_EXTENSION(BeaconFramework))

/// Convenience init to allow init with a string. -parameter urlString: The string representation of a URL to init with.
- (nullable instancetype)initWithUrlString:(NSString * __nonnull)urlString;

/// Check if the request requires the parameters to be appended to the URL
- (BOOL)isURIParam;
@end


@interface NSNumber (SWIFT_EXTENSION(BeaconFramework))
@end

@class message;

SWIFT_CLASS("_TtC15BeaconFramework12Notification")
@interface Notification : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (void)get_push_message:(NSString * __nonnull)server_ip major:(NSInteger)major minor:(NSInteger)minor key:(NSString * __nonnull)key msg:(message * __nonnull)msg;
@end

@class PushContent;

SWIFT_CLASS("_TtCC15BeaconFramework12Notification7message")
@interface message : NSObject
@property (nonatomic, strong) PushContent * __nullable content;
@property (nonatomic, copy) NSString * __nullable state;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework7Product")
@interface Product : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC15BeaconFramework11PushContent")
@interface PushContent : NSObject
@property (nonatomic, copy) NSArray<Coupon *> * __nonnull coupons;
@property (nonatomic, copy) NSArray<Product *> * __nonnull products;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class NSData;
@class NSCoder;
@class NSURL;


/// This is how to upload files in SwiftHTTP. The upload object represents a file to upload by either a data blob or a url (which it reads off disk).
SWIFT_CLASS("_TtC15BeaconFramework6Upload")
@interface Upload : NSObject <NSCoding>

/// Reads the data from disk or from memory. Throws an error if no data or file is found.
- (NSData * __nullable)getDataAndReturnError:(NSError * __nullable * __null_unspecified)error;

/// Standard NSCoder support
- (void)encodeWithCoder:(NSCoder * __nonnull)aCoder;

/// Required for NSObject support (because of NSCoder, it would be a struct otherwise!)
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;

/// Initializes a new Upload object with a fileUrl. The fileName and mimeType will be infered.
///
/// -parameter fileUrl: The fileUrl is a standard url path to a file.
- (nonnull instancetype)initWithFileUrl:(NSURL * __nonnull)fileUrl;

/// Initializes a new Upload object with a data blob.
///
/// -parameter data: The data is a NSData representation of a file's data.
/// -parameter fileName: The fileName is just that. The file's name.
/// -parameter mimeType: The mimeType is just that. The mime type you would like the file to uploaded as.
///
/// upload a file from a a data blob. Must add a filename and mimeType as that can't be infered from the data
- (nonnull instancetype)initWithData:(NSData * __nonnull)data fileName:(NSString * __nonnull)fileName mimeType:(NSString * __nonnull)mimeType;
@end


@interface Upload (SWIFT_EXTENSION(BeaconFramework))
@end

#pragma clang diagnostic pop