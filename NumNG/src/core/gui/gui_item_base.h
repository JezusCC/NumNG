#pragma once

#include "../../utils/utils.h"

namespace ngCore {
	struct Style {
		//
		uint32 width;
		uint32 height;
		//position
		int32 top;
		int32 right;
		int32 bottom;
		int32 left;
		//padding
		uint32 padding_top;
		uint32 padding_right;
		uint32 padding_bottom;
		uint32 padding_left;
		//margin
		uint32 margin_top;
		uint32 margin_right;
		uint32 margin_bottom;
		uint32 margin_left;
		//color
		ngUtils::Color color;
		ngUtils::Color background_color;
		float32 opacity;
	};

	class GuiItemBase {
	public:
		static Style GuiLightStyle;
		static Style GuiDarkStyle;
	public:
		GuiItemBase(const ngString& name);
		GuiItemBase(const GuiItemBase& other);
		virtual ~GuiItemBase();

		const ngUtils::UUID& getId()const;
		const ngString& getName()const;

		void setStyle(Style style);
		const Style& getStyle()const;

	protected:
		Style m_style;
		ngUtils::UUID m_uuid;
		ngString m_name;
	};
}