//
//  SMSavedModel.m
//  SMQuickRestKit
//
//  Created by Stefano Mondino on 25/10/13.
//  Copyright (c) 2013 Stefano Mondino. All rights reserved.
//

#import "STMSavedModel.h"
#import "STMQuickObjectMapper.h"
@implementation STMSavedModel

+(RKEntityMapping *) mappingForBaseurl:(NSString *)baseurl  {
    RKObjectManager* objectManager = [STMQuickObjectMapper objectManagerWithBaseurl:baseurl];
    if (objectManager){
        RKEntityMapping *mapping = [RKEntityMapping mappingForEntityForName:[[self class] description] inManagedObjectStore:objectManager.managedObjectStore];
        [self setupMapping:mapping forBaseurl:baseurl];
        return mapping;
    }
    return nil;
}

+(id) mappingWithKeyPath:(NSString *)keypath forBaseurl:(NSString*)baseurl path:(NSString*) path{
    RKObjectManager* objectManager = [STMQuickObjectMapper objectManagerWithBaseurl:baseurl];
    path = [[path componentsSeparatedByString:@"?"] objectAtIndex:0];
    if (objectManager){
        RKEntityMapping *mapping = [self mappingForBaseurl:baseurl];
        RKResponseDescriptor *responseDescriptor = [RKResponseDescriptor responseDescriptorWithMapping:mapping method:RKRequestMethodAny pathPattern:path keyPath:keypath statusCodes:RKStatusCodeIndexSetForClass(RKStatusCodeClassSuccessful)];
        [objectManager addResponseDescriptor: responseDescriptor];
        return mapping;
    }
    return nil;
}

+ (void) setupMapping: (RKObjectMapping*) mapping forBaseurl:(NSString *)baseurl {
    ;
}

@end
