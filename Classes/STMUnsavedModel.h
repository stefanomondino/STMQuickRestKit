//
//  STMUnsavedModel.h
//  STMQuickRestKit
//
//  Created by Stefano Mondino on 25/10/13.
//  Copyright (c) 2013 Stefano Mondino. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <RestKit.h>

/**
 Objective-C model of remote object (JSON, XML or whatever your serializer gives you back).
 Provides quick access to RestKit's mappings.
 */
@interface STMUnsavedModel : NSObject

/**
 Override this method to customize your RKObjectMapping.
 @param mapping: The RKObjectMapping to setup. 
 @param baseurl: The RKObjectManager baseurl that is currently configuring the mapping.
 */
+ (void) setupMapping: (RKObjectMapping*) mapping forBaseurl:(NSString *)baseurl;


/**
 Setup a mapping for a RKObjectManager identified by the baseurl in the global SMQuickObjectMapper for provided remote path and keypath. You should usually call this method in AppDelegate's didFinishLaunchingWithOptions for each mapping you want to configure.
 @param keypath: A key path specifying the subset of the parsed response for which the mapping is to be used.
 @param baseurl: The baseurl that identifies a RKObjectManager inside SMQuickObjectMapper.
 @param path: A path pattern that matches against URLs for which the mapping should be used.
 */
+(id) mappingWithKeyPath:(NSString *)keypath forBaseurl:(NSString*)baseurl path:(NSString*) path;

/**
 Setup a mapping for relationships between objects.
 @example: [mapping addPropertyMapping:[RKRelationshipMapping relationshipMappingFromKeyPath:@"childKeyPath" toKeyPath:@"children" withMapping:[Child mappingForBaseurl:baseurl]]];
 @param baseurl: The baseurl that identifies a RKObjectManager inside SMQuickObjectMapper.
*/
+(RKObjectMapping *) mappingForBaseurl:(NSString *)baseurl;
@end
