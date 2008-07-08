/*
    Copyright (c) 2008 NetAllied Systems GmbH
	
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#ifndef __COLLADA_MAYA_SET_HELPER_H__
#define __COLLADA_MAYA_SET_HELPER_H__

#if MAYA_API_VERSION < 600
typedef MObject MObjectHandle;
#else
# include <maya/MObjectHandle.h>
#endif

#include <vector>

class MStringArray;

class MDagPath;

class MFnSet;

namespace COLLADAMaya
{
    /**
     * todo Doku
     */

    class SetHelper
    {

    public:
        enum SetModes
        {
            kExcluding,
            kIncludeOnly
        };

        static bool setSets ( const MStringArray& sets, SetModes desiredMode );
        static bool isExcluded ( const MDagPath& dagPath );

    private:

        /** Don't create an object of this class. */
        SetHelper() {};

        /** Unlike Maya's default behavior, we want to consider set membership to be inheritable. */
        static bool isMemberOfSet ( const MDagPath& dagPath, MFnSet& Set );

    private:

        static std::vector<MObjectHandle> setObjects;
        static SetModes setMode;
    };
}

#endif // __COLLADA_MAYA_SET_HELPER_H__
