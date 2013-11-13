//
//  Plugin.h
//  BitBar
//
//  Created by Mat Ryer on 11/12/13.
//  Copyright (c) 2013 Bit Bar. All rights reserved.
//

#import <Foundation/Foundation.h>
@class PluginManager;

@interface Plugin : NSObject <NSMenuDelegate>

@property (nonatomic, copy) NSString *path;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, copy) NSString *allContent;
@property (nonatomic, assign) NSInteger currentLine;
@property (nonatomic, strong) NSArray *allContentLines;
@property (nonatomic, copy) NSString *errorContent;
@property (nonatomic, assign) BOOL lastCommandWasError;
@property (nonatomic, strong) NSNumber *refreshIntervalSeconds;
@property (readonly, nonatomic, strong) PluginManager* manager;
@property (nonatomic, assign) NSInteger cycleLinesIntervalSeconds;
@property (nonatomic, strong) NSTimer *lineCycleTimer;
@property (nonatomic, assign) BOOL pluginIsVisible;

@property (nonatomic, assign) BOOL menuIsOpen;

// UI
@property (nonatomic, strong) NSStatusItem *statusItem;

- (id) initWithManager:(PluginManager*)manager;
- (BOOL) isMultiline;

- (BOOL) refreshContentByExecutingCommand;
- (void) rebuildMenuForStatusItem:(NSStatusItem*)statusItem;
- (BOOL) refresh;
- (void) cycleLines;

// actions
- (void)changePluginsDirectorySelected:(id)sender;

@end
