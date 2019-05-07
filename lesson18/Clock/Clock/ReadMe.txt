========================================================================
    ACTIVEX CONTROL DLL : Clock Project Overview
========================================================================

ControlWizard has created this project for your Clock ActiveX Control
DLL, which contains 1 control.

This skeleton project not only demonstrates the basics of writing an
ActiveX Control, but is also a starting point for writing the specific
features of your control.

This file contains a summary of what you will find in each of the files
that make up your Clock ActiveX Control DLL.

Clock.vcxproj
    This is the main project file for VC++ projects generated using an
    Application Wizard. It contains information about the version of
    Visual C++ that generated the file, and information about the platforms,
    configurations, and project features selected with the Application Wizard.

Clock.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Clock.h
    This is the main include file for the ActiveX Control DLL.  It
    includes other project-specific includes such as resource.h.

Clock.cpp
    This is the main source file that contains code for DLL initialization,
    termination and other bookkeeping.

Clock.rc
    This is a listing of the Microsoft Windows resources that the project
    uses.  This file can be directly edited with the Visual C++ resource
    editor.

Clock.def
    This file contains information about the ActiveX Control DLL that
    must be provided to run with Microsoft Windows.

Clock.idl
    This file contains the Object Description Language source code for the
    type library of your control.

Clock.ico
    This file contains an icon that will appear in the About box.  This icon
    is included by the main resource file Clock.rc.

/////////////////////////////////////////////////////////////////////////////
CClockCtrl control:

ClockCtrl.h
    This file contains the declaration of the CClockCtrl C++ class.

ClockCtrl.cpp
    This file contains the implementation of the CClockCtrl C++ class.

ClockPropPage.h
    This file contains the declaration of the CClockPropPage C++ class.

ClockPropPage.cpp
    This file contains the implementation of the CClockPropPage C++ class.

CClockCtrl.bmp
    This file contains a bitmap that a container will use to represent the
    CClockCtrl control when it appears on a tool palette.  This bitmap
    is included by the main resource file Clock.rc.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

stdafx.h, stdafx.cpp
    These files are used to build a precompiled header (PCH) file
    named Clock.pch and a precompiled types (PCT) file named stdafx.obj.

resource.h
    This is the standard header file, which defines new resource IDs.
    The Visual C++ resource editor reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

ControlWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
