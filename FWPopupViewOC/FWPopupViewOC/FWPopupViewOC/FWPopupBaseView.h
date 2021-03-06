//
//  FWPopupBaseView.h
//  FWPopupViewOC
//
//  Created by xfg on 2018/5/25.
//  Copyright © 2018年 xfg. All rights reserved.
//

/** ************************************************
 
 github地址：https://github.com/choiceyou/FWPopupView
 bug反馈、交流群：670698309
 
 ***************************************************
 */


#import <UIKit/UIKit.h>
#import "UIView+PopupView.h"

/**
 自定义弹窗校准位置，注意：这边设置靠置哪边动画就从哪边出来

 - FWPopupAlignmentCenter: 中间，默认值
 - FWPopupAlignmentTop: 上
 - FWPopupAlignmentLeft: 左
 - FWPopupAlignmentBottom: 下
 - FWPopupAlignmentRight: 右
 - FWPopupAlignmentTopCenter: 上中
 - FWPopupAlignmentLeftCenter: 左中
 - FWPopupAlignmentBottomCenter: 下中
 - FWPopupAlignmentRightCenter: 右中
 - FWPopupAlignmentTopLeft: 上左
 - FWPopupAlignmentTopRight: 上右
 - FWPopupAlignmentBottomLeft: 下左
 - FWPopupAlignmentBottomRight: 下右
 */
typedef NS_ENUM(NSInteger, FWPopupAlignment) {
    FWPopupAlignmentCenter,
    FWPopupAlignmentTop,
    FWPopupAlignmentLeft,
    FWPopupAlignmentBottom,
    FWPopupAlignmentRight,
    FWPopupAlignmentTopCenter,
    FWPopupAlignmentLeftCenter,
    FWPopupAlignmentBottomCenter,
    FWPopupAlignmentRightCenter,
    FWPopupAlignmentTopLeft,
    FWPopupAlignmentTopRight,
    FWPopupAlignmentBottomLeft,
    FWPopupAlignmentBottomRight,
};

/**
 自定义弹窗动画类型

 - FWPopupAnimationStylePosition: 位移动画，视图靠边的时候建议使用
 - FWPopupAnimationStyleScale: 缩放动画
 - FWPopupAnimationStyleScale3D: 3D缩放动画（注意：这边隐藏时用的还是scale动画）
 - FWPopupAnimationStyleFrame: 修改frame值的动画，视图未靠边的时候建议使用
 */
typedef NS_ENUM(NSInteger, FWPopupAnimationStyle) {
    FWPopupAnimationStylePosition = 0,
    FWPopupAnimationStyleScale,
    FWPopupAnimationStyleScale3D,
    FWPopupAnimationStyleFrame,
};

/**
 弹窗箭头的样式

 - FWPopupArrowStyleNone: 无箭头
 - FWPopupArrowStyleRound: 圆角箭头
 - FWPopupArrowStyleTriangle: 菱角箭头
 */
typedef NS_ENUM(NSInteger, FWPopupArrowStyle) {
    FWPopupArrowStyleNone,
    FWPopupArrowStyleRound,
    FWPopupArrowStyleTriangle,
};

@class FWPopupBaseView;
@class FWPopupBaseViewProperty;

/**
 显示、隐藏回调

 @param popupBaseView self
 */
typedef void(^FWPopupBlock)(FWPopupBaseView *popupBaseView);

/**
 显示、隐藏完成回调

 @param popupBaseView self
 @param isShow YES：显示 NO：隐藏
 */
typedef void(^FWPopupCompletionBlock)(FWPopupBaseView *popupBaseView, BOOL isShow);

/**
 普通无参数回调
 */
typedef void(^FWPopupVoidBlock)(void);

// 隐藏所有弹窗的通知
static NSString *const FWHideAllPopupViewNotification = @"FWHideAllPopupViewNotification";


@interface FWPopupBaseView : UIView

/**
 1、当外部没有传入该参数时，默认为UIWindow的根控制器的视图，即表示弹窗放在FWPopupWindow上；
 2、当外部传入该参数时，该视图为传入的UIView，即表示弹窗放在传入的UIView上；
 */
@property (nonatomic, strong) UIView                    *attachedView;

/**
 可设置属性
 */
@property (nonatomic, strong) FWPopupBaseViewProperty   *vProperty;

/**
 单击隐藏弹窗，这个当且仅当：attachedView为用户传入的UIView并且 touchWildToHide == YES 时有效
 */
@property (nonatomic, strong) UITapGestureRecognizer    *tapGest;

/**
 当前弹窗是否可见
 */
@property (nonatomic, assign, readonly) BOOL            visible;

/**
 是否有用到键盘
 */
@property (nonatomic, assign) BOOL                      withKeyboard;


- (void)show;

- (void)showWithBlock:(FWPopupCompletionBlock)completionBlock;

- (void)hide;

- (void)hideWithBlock:(FWPopupCompletionBlock)completionBlock;

@end



@interface FWPopupBaseViewProperty: NSObject

+ (instancetype)manager;

/**
 标题字体大小
 */
@property (nonatomic, assign) CGFloat titleFontSize;
/**
 标题文字颜色
 */
@property (nonatomic, strong) UIColor *titleColor;

/**
 按钮字体大小
 */
@property (nonatomic, assign) CGFloat buttonFontSize;
/**
 按钮高度
 */
@property (nonatomic, assign) CGFloat buttonHeight;
/**
 普通按钮文字颜色
 */
@property (nonatomic, strong) UIColor *itemNormalColor;
/**
 高亮按钮文字颜色
 */
@property (nonatomic, strong) UIColor *itemHighlightColor;
/**
 选中按钮文字颜色
 */
@property (nonatomic, strong) UIColor *itemPressedColor;

/**
 上下间距
 */
@property (nonatomic, assign) CGFloat topBottomMargin;
/**
 左右间距
 */
@property (nonatomic, assign) CGFloat letfRigthMargin;
/**
 控件之间的间距
 */
@property (nonatomic, assign) CGFloat commponentMargin;

/**
 边框、分割线颜色
 */
@property (nonatomic, strong) UIColor *splitColor;
/**
 边框宽度
 */
@property (nonatomic, assign) CGFloat splitWidth;
/**
 圆角值
 */
@property (nonatomic, assign) CGFloat cornerRadius;

/**
 弹窗的背景色（注意：这边指的是弹窗而不是遮罩层，遮罩层背景色的设置是：fwMaskViewColor）
 */
@property (nonatomic, strong) UIColor *backgroundColor;
/**
 弹窗的最大高度，0：表示不限制
 */
@property (nonatomic, assign) CGFloat popupViewMaxHeight;

/**
 弹窗箭头的样式
 */
@property (nonatomic, assign) FWPopupArrowStyle popupArrowStyle;
/**
 弹窗箭头的尺寸
 */
@property (nonatomic, assign) CGSize popupArrowSize;
/**
 弹窗箭头的顶点的X值相对于弹窗的宽度，默认在弹窗X轴的一半，因此设置范围：0~1
 */
@property (nonatomic, assign) CGFloat popupArrowVertexScaleX;
/**
 弹窗圆角箭头的圆角值
 */
@property (nonatomic, assign) CGFloat popupArrowCornerRadius;
/**
 弹窗圆角箭头与边线交汇处的圆角值
 */
@property (nonatomic, assign) CGFloat popupArrowBottomCornerRadius;


// ===== 自定义弹窗（继承FWPopupView）时可能会用到 =====

/**
 弹窗校准位置
 */
@property (nonatomic, assign) FWPopupAlignment popupAlignment;
/**
 弹窗动画类型
 */
@property (nonatomic, assign) FWPopupAnimationStyle popupAnimationStyle;

/**
 弹窗偏移量
 */
@property (nonatomic, assign) UIEdgeInsets popupEdgeInsets;
/**
 遮罩层的背景色（也可以使用fwMaskViewColor），注意：该参数在弹窗隐藏后，还原为弹窗弹起时的值
 */
@property (nonatomic, strong) UIColor *maskViewColor;

/**
 0表示NO，1表示YES，YES：用户点击外部遮罩层页面可以消失，注意：该参数在弹窗隐藏后，还原为弹窗弹起时的值
 */
@property (nonatomic, copy) NSString *touchWildToHide;

/**
 显示、隐藏动画所需的时间
 */
@property (nonatomic, assign) NSTimeInterval animationDuration;

/**
 3D放射动画（当且仅当：popupAnimationStyle == .scale3D 时有效）
 */
@property (nonatomic, assign) CATransform3D transform3D;
/**
 2D放射动画
 */
@property (nonatomic, assign) CGAffineTransform transform;

@end
