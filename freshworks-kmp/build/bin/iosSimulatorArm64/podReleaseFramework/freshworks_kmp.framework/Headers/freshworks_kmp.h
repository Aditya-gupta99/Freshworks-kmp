#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class Freshworks_kmpFreshchatConfig, Freshworks_kmpFreshchatEvent, Freshworks_kmpFreshchatEventType, Freshworks_kmpFreshchatFaqFilterType, Freshworks_kmpFreshchatFaqOptions, Freshworks_kmpFreshchatManager, Freshworks_kmpFreshchatPlatformContext, Freshworks_kmpFreshchatPlatformContextCompanion, Freshworks_kmpFreshchatResult, Freshworks_kmpFreshchatResultCompanion, Freshworks_kmpFreshchatResultFailure, Freshworks_kmpFreshchatResultSuccess, Freshworks_kmpFreshchatUser, Freshworks_kmpKotlinArray<T>, Freshworks_kmpKotlinByteArray, Freshworks_kmpKotlinByteIterator, Freshworks_kmpKotlinEnum<E>, Freshworks_kmpKotlinEnumCompanion, Freshworks_kmpKotlinException, Freshworks_kmpKotlinIllegalStateException, Freshworks_kmpKotlinRuntimeException, Freshworks_kmpKotlinThrowable, UIViewController;

@protocol Freshworks_kmpFreshchatEventObserver, Freshworks_kmpKotlinComparable, Freshworks_kmpKotlinIterator;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface Freshworks_kmpBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface Freshworks_kmpBase (Freshworks_kmpBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface Freshworks_kmpMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface Freshworks_kmpMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorFreshworks_kmpKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface Freshworks_kmpNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface Freshworks_kmpByte : Freshworks_kmpNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface Freshworks_kmpUByte : Freshworks_kmpNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface Freshworks_kmpShort : Freshworks_kmpNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface Freshworks_kmpUShort : Freshworks_kmpNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface Freshworks_kmpInt : Freshworks_kmpNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface Freshworks_kmpUInt : Freshworks_kmpNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface Freshworks_kmpLong : Freshworks_kmpNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface Freshworks_kmpULong : Freshworks_kmpNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface Freshworks_kmpFloat : Freshworks_kmpNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface Freshworks_kmpDouble : Freshworks_kmpNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface Freshworks_kmpBoolean : Freshworks_kmpNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatManager")))
@interface Freshworks_kmpFreshchatManager : Freshworks_kmpBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)freshchatManager __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Freshworks_kmpFreshchatManager *shared __attribute__((swift_name("shared")));
- (id<Freshworks_kmpFreshchatEventObserver>)addEventObserverObserver:(id<Freshworks_kmpFreshchatEventObserver>)observer __attribute__((swift_name("addEventObserver(observer:)")));
- (void)handlePushNotificationPayload:(NSDictionary<NSString *, id> *)payload __attribute__((swift_name("handlePushNotification(payload:)")));
- (void)identifyUserExternalId:(NSString *)externalId restoreId:(NSString * _Nullable)restoreId __attribute__((swift_name("identifyUser(externalId:restoreId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)initializeConfig:(Freshworks_kmpFreshchatConfig *)config completionHandler:(void (^)(Freshworks_kmpFreshchatResult * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("initialize(config:completionHandler:)")));
- (BOOL)isFreshchatNotificationPayload:(NSDictionary<NSString *, id> *)payload __attribute__((swift_name("isFreshchatNotification(payload:)")));
- (void)removeEventObserverObserver:(id<Freshworks_kmpFreshchatEventObserver>)observer __attribute__((swift_name("removeEventObserver(observer:)")));
- (void)resetUser __attribute__((swift_name("resetUser()")));
- (void)restoreUserWithTokenJwtToken:(NSString *)jwtToken __attribute__((swift_name("restoreUserWithToken(jwtToken:)")));

/** On iOS pass the FCM token string (if using FCM for APNs delivery). */
- (void)setPushRegistrationTokenToken:(NSString *)token __attribute__((swift_name("setPushRegistrationToken(token:)")));

/** Pass the raw APNS deviceToken bytes from didRegisterForRemoteNotificationsWithDeviceToken. */
- (void)setPushRegistrationTokenDataTokenData:(Freshworks_kmpKotlinByteArray *)tokenData __attribute__((swift_name("setPushRegistrationTokenData(tokenData:)")));
- (void)setUserUser:(Freshworks_kmpFreshchatUser *)user __attribute__((swift_name("setUser(user:)")));
- (void)setUserPropertiesProperties:(NSDictionary<NSString *, NSString *> *)properties __attribute__((swift_name("setUserProperties(properties:)")));
- (void)showConversationsPlatformContext:(Freshworks_kmpFreshchatPlatformContext * _Nullable)platformContext options:(Freshworks_kmpFreshchatFaqOptions * _Nullable)options __attribute__((swift_name("showConversations(platformContext:options:)")));
- (void)showFAQsPlatformContext:(Freshworks_kmpFreshchatPlatformContext * _Nullable)platformContext options:(Freshworks_kmpFreshchatFaqOptions * _Nullable)options __attribute__((swift_name("showFAQs(platformContext:options:)")));
- (void)trackEventName:(NSString *)name properties:(NSDictionary<NSString *, id> * _Nullable)properties __attribute__((swift_name("trackEvent(name:properties:)")));

/**
 * Call when you want to release observers (e.g. app going to background for good).
 */
- (void)unregisterObservers __attribute__((swift_name("unregisterObservers()")));
@property (readonly) BOOL isInitialized __attribute__((swift_name("isInitialized")));
@end


/**
 * Configuration for initializing the Freshchat SDK.
 *
 * @param appId         Your Freshchat App ID (Admin > Mobile SDK)
 * @param appKey        Your Freshchat App Key
 * @param domain        Your Freshchat domain e.g. "msdk.in.freshchat.com"
 * @param cameraCaptureEnabled      Allow camera capture in chat
 * @param gallerySelectionEnabled   Allow gallery selection in chat
 * @param responseExpectationEnabled Show response time expectation
 * @param teamMemberInfoVisible     Show agent avatar
 * @param fileAttachmentEnabled     Allow file attachments
 * @param showNotificationBanner    iOS only: show in-app notification banner
 * @param notificationSoundEnabled  iOS only: play notification sound
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatConfig")))
@interface Freshworks_kmpFreshchatConfig : Freshworks_kmpBase
- (instancetype)initWithAppId:(NSString *)appId appKey:(NSString *)appKey domain:(NSString *)domain cameraCaptureEnabled:(BOOL)cameraCaptureEnabled gallerySelectionEnabled:(BOOL)gallerySelectionEnabled responseExpectationEnabled:(BOOL)responseExpectationEnabled teamMemberInfoVisible:(BOOL)teamMemberInfoVisible fileAttachmentEnabled:(BOOL)fileAttachmentEnabled showNotificationBanner:(BOOL)showNotificationBanner notificationSoundEnabled:(BOOL)notificationSoundEnabled __attribute__((swift_name("init(appId:appKey:domain:cameraCaptureEnabled:gallerySelectionEnabled:responseExpectationEnabled:teamMemberInfoVisible:fileAttachmentEnabled:showNotificationBanner:notificationSoundEnabled:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatConfig *)doCopyAppId:(NSString *)appId appKey:(NSString *)appKey domain:(NSString *)domain cameraCaptureEnabled:(BOOL)cameraCaptureEnabled gallerySelectionEnabled:(BOOL)gallerySelectionEnabled responseExpectationEnabled:(BOOL)responseExpectationEnabled teamMemberInfoVisible:(BOOL)teamMemberInfoVisible fileAttachmentEnabled:(BOOL)fileAttachmentEnabled showNotificationBanner:(BOOL)showNotificationBanner notificationSoundEnabled:(BOOL)notificationSoundEnabled __attribute__((swift_name("doCopy(appId:appKey:domain:cameraCaptureEnabled:gallerySelectionEnabled:responseExpectationEnabled:teamMemberInfoVisible:fileAttachmentEnabled:showNotificationBanner:notificationSoundEnabled:)")));

/**
 * Configuration for initializing the Freshchat SDK.
 *
 * @param appId         Your Freshchat App ID (Admin > Mobile SDK)
 * @param appKey        Your Freshchat App Key
 * @param domain        Your Freshchat domain e.g. "msdk.in.freshchat.com"
 * @param cameraCaptureEnabled      Allow camera capture in chat
 * @param gallerySelectionEnabled   Allow gallery selection in chat
 * @param responseExpectationEnabled Show response time expectation
 * @param teamMemberInfoVisible     Show agent avatar
 * @param fileAttachmentEnabled     Allow file attachments
 * @param showNotificationBanner    iOS only: show in-app notification banner
 * @param notificationSoundEnabled  iOS only: play notification sound
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Configuration for initializing the Freshchat SDK.
 *
 * @param appId         Your Freshchat App ID (Admin > Mobile SDK)
 * @param appKey        Your Freshchat App Key
 * @param domain        Your Freshchat domain e.g. "msdk.in.freshchat.com"
 * @param cameraCaptureEnabled      Allow camera capture in chat
 * @param gallerySelectionEnabled   Allow gallery selection in chat
 * @param responseExpectationEnabled Show response time expectation
 * @param teamMemberInfoVisible     Show agent avatar
 * @param fileAttachmentEnabled     Allow file attachments
 * @param showNotificationBanner    iOS only: show in-app notification banner
 * @param notificationSoundEnabled  iOS only: play notification sound
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Configuration for initializing the Freshchat SDK.
 *
 * @param appId         Your Freshchat App ID (Admin > Mobile SDK)
 * @param appKey        Your Freshchat App Key
 * @param domain        Your Freshchat domain e.g. "msdk.in.freshchat.com"
 * @param cameraCaptureEnabled      Allow camera capture in chat
 * @param gallerySelectionEnabled   Allow gallery selection in chat
 * @param responseExpectationEnabled Show response time expectation
 * @param teamMemberInfoVisible     Show agent avatar
 * @param fileAttachmentEnabled     Allow file attachments
 * @param showNotificationBanner    iOS only: show in-app notification banner
 * @param notificationSoundEnabled  iOS only: play notification sound
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *appId __attribute__((swift_name("appId")));
@property (readonly) NSString *appKey __attribute__((swift_name("appKey")));
@property (readonly) BOOL cameraCaptureEnabled __attribute__((swift_name("cameraCaptureEnabled")));
@property (readonly) NSString *domain __attribute__((swift_name("domain")));
@property (readonly) BOOL fileAttachmentEnabled __attribute__((swift_name("fileAttachmentEnabled")));
@property (readonly) BOOL gallerySelectionEnabled __attribute__((swift_name("gallerySelectionEnabled")));
@property (readonly) BOOL notificationSoundEnabled __attribute__((swift_name("notificationSoundEnabled")));
@property (readonly) BOOL responseExpectationEnabled __attribute__((swift_name("responseExpectationEnabled")));
@property (readonly) BOOL showNotificationBanner __attribute__((swift_name("showNotificationBanner")));
@property (readonly) BOOL teamMemberInfoVisible __attribute__((swift_name("teamMemberInfoVisible")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatEvent")))
@interface Freshworks_kmpFreshchatEvent : Freshworks_kmpBase
- (instancetype)initWithType:(Freshworks_kmpFreshchatEventType *)type rawName:(NSString *)rawName data:(NSDictionary<NSString *, id> *)data __attribute__((swift_name("init(type:rawName:data:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatEvent *)doCopyType:(Freshworks_kmpFreshchatEventType *)type rawName:(NSString *)rawName data:(NSDictionary<NSString *, id> *)data __attribute__((swift_name("doCopy(type:rawName:data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, id> *data __attribute__((swift_name("data")));
@property (readonly) NSString *rawName __attribute__((swift_name("rawName")));
@property (readonly) Freshworks_kmpFreshchatEventType *type __attribute__((swift_name("type")));
@end

__attribute__((swift_name("FreshchatEventObserver")))
@protocol Freshworks_kmpFreshchatEventObserver
@required
- (void)onEventEvent:(Freshworks_kmpFreshchatEvent *)event __attribute__((swift_name("onEvent(event:)")));

/** Convenience — implemented on actual sides. */
- (void)unregister __attribute__((swift_name("unregister()")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol Freshworks_kmpKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface Freshworks_kmpKotlinEnum<E> : Freshworks_kmpBase <Freshworks_kmpKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Freshworks_kmpKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatEventType")))
@interface Freshworks_kmpFreshchatEventType : Freshworks_kmpKotlinEnum<Freshworks_kmpFreshchatEventType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Freshworks_kmpFreshchatEventType *restoreIdGenerated __attribute__((swift_name("restoreIdGenerated")));
@property (class, readonly) Freshworks_kmpFreshchatEventType *jwtTokenStatusChange __attribute__((swift_name("jwtTokenStatusChange")));
@property (class, readonly) Freshworks_kmpFreshchatEventType *unreadMessageCountChanged __attribute__((swift_name("unreadMessageCountChanged")));
@property (class, readonly) Freshworks_kmpFreshchatEventType *other __attribute__((swift_name("other")));
+ (Freshworks_kmpKotlinArray<Freshworks_kmpFreshchatEventType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Freshworks_kmpFreshchatEventType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatFaqFilterType")))
@interface Freshworks_kmpFreshchatFaqFilterType : Freshworks_kmpKotlinEnum<Freshworks_kmpFreshchatFaqFilterType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) Freshworks_kmpFreshchatFaqFilterType *category __attribute__((swift_name("category")));
@property (class, readonly) Freshworks_kmpFreshchatFaqFilterType *article __attribute__((swift_name("article")));
+ (Freshworks_kmpKotlinArray<Freshworks_kmpFreshchatFaqFilterType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<Freshworks_kmpFreshchatFaqFilterType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatFaqOptions")))
@interface Freshworks_kmpFreshchatFaqOptions : Freshworks_kmpBase
- (instancetype)initWithTags:(NSArray<NSString *> * _Nullable)tags filteredViewTitle:(NSString * _Nullable)filteredViewTitle filterType:(Freshworks_kmpFreshchatFaqFilterType *)filterType showFaqCategoriesAsGrid:(BOOL)showFaqCategoriesAsGrid showContactUsOnFaqScreens:(BOOL)showContactUsOnFaqScreens showContactUsOnFaqNotHelpful:(BOOL)showContactUsOnFaqNotHelpful showContactUsOnAppBar:(BOOL)showContactUsOnAppBar __attribute__((swift_name("init(tags:filteredViewTitle:filterType:showFaqCategoriesAsGrid:showContactUsOnFaqScreens:showContactUsOnFaqNotHelpful:showContactUsOnAppBar:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatFaqOptions *)doCopyTags:(NSArray<NSString *> * _Nullable)tags filteredViewTitle:(NSString * _Nullable)filteredViewTitle filterType:(Freshworks_kmpFreshchatFaqFilterType *)filterType showFaqCategoriesAsGrid:(BOOL)showFaqCategoriesAsGrid showContactUsOnFaqScreens:(BOOL)showContactUsOnFaqScreens showContactUsOnFaqNotHelpful:(BOOL)showContactUsOnFaqNotHelpful showContactUsOnAppBar:(BOOL)showContactUsOnAppBar __attribute__((swift_name("doCopy(tags:filteredViewTitle:filterType:showFaqCategoriesAsGrid:showContactUsOnFaqScreens:showContactUsOnFaqNotHelpful:showContactUsOnAppBar:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Freshworks_kmpFreshchatFaqFilterType *filterType __attribute__((swift_name("filterType")));
@property (readonly) NSString * _Nullable filteredViewTitle __attribute__((swift_name("filteredViewTitle")));
@property (readonly) BOOL showContactUsOnAppBar __attribute__((swift_name("showContactUsOnAppBar")));
@property (readonly) BOOL showContactUsOnFaqNotHelpful __attribute__((swift_name("showContactUsOnFaqNotHelpful")));
@property (readonly) BOOL showContactUsOnFaqScreens __attribute__((swift_name("showContactUsOnFaqScreens")));
@property (readonly) BOOL showFaqCategoriesAsGrid __attribute__((swift_name("showFaqCategoriesAsGrid")));
@property (readonly) NSArray<NSString *> * _Nullable tags __attribute__((swift_name("tags")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatPlatformContext")))
@interface Freshworks_kmpFreshchatPlatformContext : Freshworks_kmpBase
- (instancetype)initWithViewController:(UIViewController * _Nullable)viewController __attribute__((swift_name("init(viewController:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) Freshworks_kmpFreshchatPlatformContextCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatPlatformContext.Companion")))
@interface Freshworks_kmpFreshchatPlatformContextCompanion : Freshworks_kmpBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Freshworks_kmpFreshchatPlatformContextCompanion *shared __attribute__((swift_name("shared")));
- (Freshworks_kmpFreshchatPlatformContext *)fromViewControllerVc:(UIViewController *)vc __attribute__((swift_name("fromViewController(vc:)")));

/** Infer the top-most presented view controller automatically. */
- (Freshworks_kmpFreshchatPlatformContext *)inferred __attribute__((swift_name("inferred()")));
@end

__attribute__((swift_name("FreshchatResult")))
@interface Freshworks_kmpFreshchatResult : Freshworks_kmpBase
@property (class, readonly, getter=companion) Freshworks_kmpFreshchatResultCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) BOOL isFailure __attribute__((swift_name("isFailure")));
@property (readonly) BOOL isSuccess __attribute__((swift_name("isSuccess")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatResult.Companion")))
@interface Freshworks_kmpFreshchatResultCompanion : Freshworks_kmpBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Freshworks_kmpFreshchatResultCompanion *shared __attribute__((swift_name("shared")));
- (Freshworks_kmpFreshchatResult *)failureMessage:(NSString *)message __attribute__((swift_name("failure(message:)")));
- (Freshworks_kmpFreshchatResult *)failureError:(Freshworks_kmpKotlinThrowable *)error __attribute__((swift_name("failure(error:)")));
- (Freshworks_kmpFreshchatResult *)successMessage:(NSString *)message metadata:(NSDictionary<NSString *, id> *)metadata __attribute__((swift_name("success(message:metadata:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatResult.Failure")))
@interface Freshworks_kmpFreshchatResultFailure : Freshworks_kmpFreshchatResult
- (instancetype)initWithError:(Freshworks_kmpKotlinThrowable *)error message:(NSString *)message __attribute__((swift_name("init(error:message:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatResultFailure *)doCopyError:(Freshworks_kmpKotlinThrowable *)error message:(NSString *)message __attribute__((swift_name("doCopy(error:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Freshworks_kmpKotlinThrowable *error __attribute__((swift_name("error")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatResult.Success")))
@interface Freshworks_kmpFreshchatResultSuccess : Freshworks_kmpFreshchatResult
- (instancetype)initWithMessage:(NSString *)message metadata:(NSDictionary<NSString *, id> *)metadata __attribute__((swift_name("init(message:metadata:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatResultSuccess *)doCopyMessage:(NSString *)message metadata:(NSDictionary<NSString *, id> *)metadata __attribute__((swift_name("doCopy(message:metadata:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) NSDictionary<NSString *, id> *metadata __attribute__((swift_name("metadata")));
@end


/**
 * Represents a Freshchat user.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FreshchatUser")))
@interface Freshworks_kmpFreshchatUser : Freshworks_kmpBase
- (instancetype)initWithFirstName:(NSString * _Nullable)firstName lastName:(NSString * _Nullable)lastName email:(NSString * _Nullable)email phoneCountryCode:(NSString * _Nullable)phoneCountryCode phone:(NSString * _Nullable)phone __attribute__((swift_name("init(firstName:lastName:email:phoneCountryCode:phone:)"))) __attribute__((objc_designated_initializer));
- (Freshworks_kmpFreshchatUser *)doCopyFirstName:(NSString * _Nullable)firstName lastName:(NSString * _Nullable)lastName email:(NSString * _Nullable)email phoneCountryCode:(NSString * _Nullable)phoneCountryCode phone:(NSString * _Nullable)phone __attribute__((swift_name("doCopy(firstName:lastName:email:phoneCountryCode:phone:)")));

/**
 * Represents a Freshchat user.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents a Freshchat user.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a Freshchat user.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable email __attribute__((swift_name("email")));
@property (readonly) NSString * _Nullable firstName __attribute__((swift_name("firstName")));
@property (readonly) NSString * _Nullable lastName __attribute__((swift_name("lastName")));
@property (readonly) NSString * _Nullable phone __attribute__((swift_name("phone")));
@property (readonly) NSString * _Nullable phoneCountryCode __attribute__((swift_name("phoneCountryCode")));
@end

__attribute__((swift_name("KotlinThrowable")))
@interface Freshworks_kmpKotlinThrowable : Freshworks_kmpBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (Freshworks_kmpKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) Freshworks_kmpKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface Freshworks_kmpKotlinException : Freshworks_kmpKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface Freshworks_kmpKotlinRuntimeException : Freshworks_kmpKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface Freshworks_kmpKotlinIllegalStateException : Freshworks_kmpKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface Freshworks_kmpKotlinCancellationException : Freshworks_kmpKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(Freshworks_kmpKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface Freshworks_kmpKotlinByteArray : Freshworks_kmpBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(Freshworks_kmpByte *(^)(Freshworks_kmpInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (Freshworks_kmpKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface Freshworks_kmpKotlinEnumCompanion : Freshworks_kmpBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) Freshworks_kmpKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface Freshworks_kmpKotlinArray<T> : Freshworks_kmpBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(Freshworks_kmpInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<Freshworks_kmpKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol Freshworks_kmpKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface Freshworks_kmpKotlinByteIterator : Freshworks_kmpBase <Freshworks_kmpKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (Freshworks_kmpByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
