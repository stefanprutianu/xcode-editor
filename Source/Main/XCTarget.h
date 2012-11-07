////////////////////////////////////////////////////////////////////////////////
//
//  JASPER BLUES
//  Copyright 2012 Jasper Blues
//  All Rights Reserved.
//
//  NOTICE: Jasper Blues permits you to use, modify, and distribute this file
//  in accordance with the terms of the license agreement accompanying it.
//
////////////////////////////////////////////////////////////////////////////////


#import <Foundation/Foundation.h>


typedef enum {
	XCTargetBuildPhaseCopyBundleResources,
	XCTargetBuildPhaseLinking,
	XCTargetBuildPhaseShellScript,
	XCTargetBuildPhaseSourcesBuild,
	XCTargetBuildPhaseCopyHeaders
}XCTargetBuildPhase;

@class XCProject;
@class XCSourceFile;
@class XCBuildConfigurationList;

/**
* Represents a target in an xcode project.
*/
@interface XCTarget : NSObject {

    XCProject* _project;
    NSString* _key;
    NSString* _name;
    NSString* _productName;
    NSString* _productReference;
	 NSString* _defaultConfigurationName;

@private
    NSMutableArray* _members;
    NSMutableArray* _resources;
    NSMutableDictionary* _configurations;
}

@property(nonatomic, strong, readonly) NSString* key;
@property(nonatomic, strong, readonly) NSString* name;
@property(nonatomic, strong, readonly) NSString* productName;
@property(nonatomic, strong, readonly) NSString* productReference;

+ (XCTarget*) targetWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName productReference:(NSString*)productReference;

- (id) initWithProject:(XCProject*)project key:(NSString*)key name:(NSString*)name productName:(NSString*)productName productReference:(NSString*)productReference;

- (NSArray*) resources;
- (NSArray*) members;

- (NSDictionary*) configurations;
- (XCBuildConfigurationList*)defaultConfiguration;	

- (void) addMember:(XCSourceFile*)member;

- (void) removeMemberWithKey:(NSString*)key;

- (void) removeMembersWithKeys:(NSArray*)keys;

- (void) addDependency:(NSString*)key;

/*  retrives the key in project raw data used to reference a build phase */
- (NSString *)keyForBuildPhase:(XCTargetBuildPhase)phase;

/* retrieves the PBXBuildFile entry in project raw data where fileRef is equal with the given one  */
- (NSString *)keyForBuildFileInPhase:(XCTargetBuildPhase)phase fileReference:(NSString*)fileRef;

/* similar with the above but it figures out the phase by looking at file type */
- (NSString*)keyForBuildPhaseFileReferenceForFile:(XCSourceFile*)file;

@end

