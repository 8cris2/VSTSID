/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Igor Zinken - https://www.igorski.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Bundle Identifier */
#define kAudioUnitBundleIdentifier  nl.igorski.vst3plugin.vstsid.audiounit
/* Version Number (needs to be in hex)*/
#define kAudioUnitVersion           0xFFFFFFFF
/* Company Name + Effect Name */
#define kAUPluginName               Igorski: VSTSID
/* Effect Description */
#define kAUPluginDescription        VSTSID
/* Audio Unit Type, this is enumerated in AUComponent.h */
#define kAUPluginType               aumu
/* Unique ID */
#define kAUPluginSubType            chip
/* Registered Company ID */
#define kAUPluginManufacturer       Igorski

// Definitions for the resource file
#define kAudioUnitName              "Igorski: VSTSID"   // same as kAUPluginName
#define kAudioUnitDescription       "VSTSID"            // same as kAUPluginDescription
#define kAudioUnitType              'aumu'              // kAudioUnitType_Effect // same as kAUPluginType
#define kAudioUnitComponentSubType  'chip'              // same as kAUPluginSubType
#define kAudioUnitComponentManuf    'Igorski'           // same as kAUPluginManufacturer

#define kAudioUnitCarbonView        1   // if 0 no Carbon view support will be added
