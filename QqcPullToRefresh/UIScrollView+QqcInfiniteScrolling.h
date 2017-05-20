//
// UIScrollView+QqcInfiniteScrolling.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>

@class QqcInfiniteScrollingView;

@interface UIScrollView (QqcInfiniteScrolling)

- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;
- (void)triggerInfiniteScrolling;

@property (nonatomic, strong, readonly) QqcInfiniteScrollingView *infiniteScrollingView;
@property (nonatomic, assign) BOOL showsInfiniteScrolling;

@end


enum {
	QqcInfiniteScrollingStateStopped = 0,
    QqcInfiniteScrollingStateTriggered,
    QqcInfiniteScrollingStateLoading,
    QqcInfiniteScrollingStateAll = 10
};

typedef NSUInteger QqcInfiniteScrollingState;

@interface QqcInfiniteScrollingView : UIView

@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, readonly) QqcInfiniteScrollingState state;
@property (nonatomic, readwrite) BOOL enabled;

- (void)setCustomView:(UIView *)view forState:(QqcInfiniteScrollingState)state;

- (void)startAnimating;
- (void)stopAnimating;

@end
