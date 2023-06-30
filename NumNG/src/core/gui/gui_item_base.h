#pragma once

#include "../utils/utils.h"

namespace ngCore {
	struct Style {
		//position
		uint32 top;
		uint32 right;
		uint32 bottom;
		uint32 left;
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
		ngUtil::Color color;
		ngUtil::Color background_color;
	};

	class GuiItemBase {
	public:
		static Style GuiLightStyle;
		static Style GuiDarkStyle;
	public:
		GuiItemBase(const ngString& name);
		GuiItemBase(const GuiItemBase& other);
		virtual ~GuiItemBase();

		const ngUtil::UUID& getId()const;
		const ngString& getName()const;

		void setStyle(Style style);
		Style getStyle()const;

	protected:
		Style m_style;
		ngUtil::UUID m_uuid;
		ngString m_name;
	};
}