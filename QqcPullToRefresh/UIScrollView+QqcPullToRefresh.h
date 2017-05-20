//
// UIScrollView+QqcPullToRefresh.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>


@class QqcPullToRefreshView;

@interface UIScrollView (QqcPullToRefresh)

typedef NS_ENUM(NSUInteger, QqcPullToRefreshPosition) {
    QqcPullToRefreshPositionTop = 0,
    QqcPullToRefreshPositionBottom,
};

- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler;
- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler position:(QqcPullToRefreshPosition)position;
- (void)triggerPullToRefresh;

@property (nonatomic, strong, readonly) QqcPullToRefreshView *pullToRefreshView;
@property (nonatomic, assign) BOOL showsPullToRefresh;

@end


typedef NS_ENUM(NSUInteger, QqcPullToRefreshState) {
    QqcPullToRefreshStateStopped = 0,
    QqcPullToRefreshStateTriggered,
    QqcPullToRefreshStateLoading,
    QqcPullToRefreshStateAll = 10
};

@interface QqcPullToRefreshView : UIView

@property (nonatomic, strong) UIColor *arrowColor;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonatomic, strong, readonly) UILabel *subtitleLabel;
@property (nonatomic, strong, readwrite) UIColor *activityIndicatorViewColor NS_AVAILABLE_IOS(5_0);
@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;

@property (nonatomic, readonly) QqcPullToRefreshState state;
@property (nonatomic, readonly) QqcPullToRefreshPosition position;

- (void)setTitle:(NSString *)title forState:(QqcPullToRefreshState)state;
- (void)setSubtitle:(NSString *)subtitle forState:(QqcPullToRefreshState)state;
- (void)setCustomView:(UIView *)view forState:(QqcPullToRefreshState)state;

- (void)startAnimating;
- (void)stopAnimating;

// deprecated; use setSubtitle:forState: instead
@property (nonatomic, strong, readonly) UILabel *dateLabel DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) NSDate *lastUpdatedDate DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) NSDateFormatter *dateFormatter DEPRECATED_ATTRIBUTE;

// deprecated; use [self.scrollView triggerPullToRefresh] instead
- (void)triggerRefresh DEPRECATED_ATTRIBUTE;

@end
