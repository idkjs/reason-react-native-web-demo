module type TextComponent = {
  let make:
    (
      ~accessibilityRole: string=?,
      ~accessible: bool=?,
      ~allowFontScaling: bool=?,
      ~ellipsizeMode: [ | `clip | `head | `middle | `tail]=?,
      ~numberOfLines: int=?,
      ~onLayout: BsReactNative.RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLongPress: unit => unit=?,
      ~onPress: unit => unit=?,
      ~pressRetentionOffset: BsReactNative.Types.insets=?,
      ~selectable: bool=?,
      ~style: BsReactNative.Style.t=?,
      ~testID: string=?,
      ~selectionColor: string=?,
      ~textBreakStrategy: [ | `simple | `highQuality | `balanced]=?,
      ~adjustsFontSizeToFit: bool=?,
      ~minimumFontScale: float=?,
      ~suppressHighlighting: bool=?,
      ~value: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module type Impl = {let view: ReasonReact.reactClass;};

module CreateComponent = (Impl: Impl) : TextComponent => {
  let make =
      (
        ~accessibilityRole=?,
        ~accessible=?,
        ~allowFontScaling=?,
        ~ellipsizeMode=?,
        ~numberOfLines=?,
        ~onLayout=?,
        ~onLongPress=?,
        ~onPress=?,
        ~pressRetentionOffset=?,
        ~selectable=?,
        ~style=?,
        ~testID=?,
        ~selectionColor=?,
        ~textBreakStrategy=?,
        ~adjustsFontSizeToFit=?,
        ~minimumFontScale=?,
        ~suppressHighlighting=?,
        ~value=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props={
        "accessibilityRole": accessibilityRole,
        "accessible": accessible,
        "allowFontScaling": allowFontScaling,
        "ellipsizeMode":
          UtilsRN.option_map(
            fun
            | `head => "head"
            | `middle => "middle"
            | `tail => "tail"
            | `clip => "clip",
            ellipsizeMode,
          ),
        "numberOfLines": numberOfLines,
        "onLayout": onLayout,
        "onLongPress": onLongPress,
        "onPress": onPress,
        "pressRetentionOffset": pressRetentionOffset,
        "selectable": selectable,
        "style": style,
        "testID": testID,
        "selectionColor": selectionColor,
        "textBreakStrategy":
          UtilsRN.option_map(
            fun
            | `simple => "simple"
            | `highQuality => "highQuality"
            | `balanced => "balanced",
            textBreakStrategy,
          ),
        "adjustsFontSizeToFit": adjustsFontSizeToFit,
        "minimumFontScale": minimumFontScale,
        "suppressHighlighting": suppressHighlighting,
      },
      switch (value) {
      | Some(string) =>
        Array.append([|ReasonReact.string(string)|], children)
      | None => children
      },
    );
};

include CreateComponent({
  [@bs.module "react-native"] external view: ReasonReact.reactClass = "Text";
});
