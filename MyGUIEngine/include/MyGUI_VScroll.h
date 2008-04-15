/*!
	@file
	@author		Albert Semenov
	@date		11/2007
	@module
*/
#ifndef __MYGUI_VSCROLL_H__
#define __MYGUI_VSCROLL_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_Widget.h"

namespace MyGUI
{

	class _MyGUIExport VScroll : public Widget
	{
		// ��� ������ ��������� ������������
		friend class factory::VScrollFactory;

	protected:
		VScroll(const IntCoord& _coord, Align _align, const WidgetSkinInfoPtr _info, CroppedRectanglePtr _parent, WidgetCreator * _creator, const Ogre::String & _name);

		static Ogre::String WidgetTypeName;

	public:
		//! @copydoc Widget::_getType()
		inline static const Ogre::String & _getType() {return WidgetTypeName;}
		//!	@copydoc Widget::getWidgetType()
		virtual const Ogre::String & getWidgetType() { return _getType(); }

		void setScrollRange(size_t _range);
		inline size_t getScrollRange() {return mScrollRange;}

		void setScrollPosition(size_t _position);
		inline size_t getScrollPosition() {return mScrollPosition;}

		inline void setScrollPage(size_t _page = 1) {mScrollPage = _page;}
		inline size_t getScrollPage() {return mScrollPage;}

		inline void setScrollViewPage(size_t _viewPage = 1) {mScrollViewPage = _viewPage;}
		inline size_t getScrollViewPage() {return mScrollViewPage;}

		virtual void setSize(const IntSize& _size);
		virtual void setPosition(const IntCoord& _coord);

		inline void setPosition(int _left, int _top) {Widget::setPosition(IntPoint(_left, _top));}
		inline void setPosition(int _left, int _top, int _width, int _height) {setPosition(IntCoord(_left, _top, _width, _height));}
		inline void setSize(int _width, int _height) {setSize(IntSize(_width, _height));}

		// event : ���������� ��������� ������
		// signature : void method(MyGUI::WidgetPtr _sender, size_t _position)
		EventInfo_WidgetSizeT eventScrollChangePosition;

	protected:
		virtual void updateTrack();
		virtual void TrackMove(int _left, int _top);
		void notifyMousePressed(MyGUI::WidgetPtr _sender, bool _left);
		void notifyMouseReleased(MyGUI::WidgetPtr _sender, bool _left);
		void notifyMouseDrag(MyGUI::WidgetPtr _sender, int _left, int _top);

		// ���� ������
		ButtonPtr mWidgetStart;
		ButtonPtr mWidgetEnd;
		ButtonPtr mWidgetTrack;
		// ����� ����� ��������
		ButtonPtr mWidgetFirstPart;
		ButtonPtr mWidgetSecondPart;

		// ������� ���� ����� ������� ��� ���������
		IntRect mPreActionRect;

		// �������� �� ������� ���� ����� ���������
		size_t mSkinRangeStart;
		size_t mSkinRangeEnd;

		size_t mScrollRange;
		size_t mScrollPosition;
		size_t mScrollPage; // �� ������� �������������, ��� ������ �� ������
		size_t mScrollViewPage; // �� ������� �������������, ��� ������ �� ������

	}; // class VScroll : public Widget

} // namespace MyGUI

#endif // __MYGUI_VSCROLL_H__
