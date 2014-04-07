//
//  STMSavedModel.h
//  STMQuickRestKit
//
//  Created by Stefano Mondino on 25/10/13.
//  Copyright (c) 2013 Stefano Mondino. All rights reserved.
//

#import <CoreData/CoreData.h>
#import <RestKit.h>

@interface STMSavedModel : NSManagedObject
+(id) mappingWithKeyPath:(NSString *)keypath forBaseurl:(NSString*)baseurl path:(NSString*) path;
+ (void) setupMapping: (RKObjectMapping*) mapping forBaseurl:(NSString *)baseurl;
//Used in child mappings
+(RKEntityMapping *) mappingForBaseurl:(NSString *)baseurl;
@end
