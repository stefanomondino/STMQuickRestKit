//
//  STMQuickObjectMapper.h
//  STMQuickRestKit
//
//  Created by Stefano Mondino on 25/10/13.
//  Copyright (c) 2013 Stefano Mondino. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFHTTPClient.h>
#import <CoreData.h>
#import <RestKit.h>
/**
 Application-wide manager of RKObjectManagers (where a single RKObjectManager is uniquely identified by its baseurl).
 */
@interface STMQuickObjectMapper : NSObject

/**
 Singleton instance of STMQuickObjectManager
 @return: A singleton instance of STMQuickObjectManager
 */
+ (STMQuickObjectMapper *) sharedObjectMapper;

/**
 Returns a list of all RKObjectManagers configured in STMQuickObjectManager
 @return: A NSDictionary containing all RKObjectManagers as values and corresponding baseurl as keys
 */
- (NSDictionary*) allObjectManagers;

/**
 @see (AFHTTPClient*) initWithURL:(NSURL *)baseurl shouldUseCoreData:(BOOL) shouldUseCoreData;
 */
+ (AFHTTPClient*) initWithBaseurl:(NSString*) baseurl shouldUseCoreData:(BOOL) shouldUseCoreData;

/**
 Initialize a new RKObjectManager and adds it to the STMQuickObjectMapper.
 MagicalRecord is automatically configured to work with RestKit (with automigrating CoreData stack) when needed.
 @param baseurl: The baseurl for the RKObjectManager
 @param shouldUseCoreData: Set this to NO if NONE of all mappings associated to this RKObjectMaanager will be persisted in CoreData (none of them should be a NSManagedObject). If YES, it will automatically configure MagicalRecord to work on the same contexts of RestKit. @note: It's safe to set this to YES and have some of your mappings not persisted.
 @return : The AFHTTPClient associated to the RKObjectManager
 */
+ (AFHTTPClient*) initWithURL:(NSURL *)baseurl shouldUseCoreData:(BOOL) shouldUseCoreData;

/**
 Wraps RestKit's + (void) registerClass:(Class) class forMIMEType:(id)MIMETypeStringOrRegularExpression and configures different MIMETypes to work with specified serializatiors. It's wrapped here for better visibility.
 @example: [STMQuickObjectMapper registerClass:[RKXMLSerialization class] forMIMEType:@"text/xml"]
 @param class: Serializator class to use with specified MIMEType
 @param MIMETypeStringOrRegularExpression: MIMEType
 
 @see RKMIMETypeSerialization#regigisterClass:forMIMEType:

 */
+ (void) registerClass:(Class) class forMIMEType:(id)MIMETypeStringOrRegularExpression;

/**
 Returns an object manager associated to specified baseurl
 @param baseurl : The baseurl associated to desired RKObjectManager
 @return: A RKObjectManager associated to baseurl or nil if no object manager was properly configured.
*/
+ (RKObjectManager*) objectManagerWithBaseurl:(NSString*) baseurl;

@end
