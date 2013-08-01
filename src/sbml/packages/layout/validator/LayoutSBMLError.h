/**
 * @file:   LayoutSBMLError.h
 * @brief:  Implementation of the LayoutSBMLError class
 * @author: Generated by autocreate code
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#ifndef LayoutSBMLError_H__
#define LayoutSBMLError_H__



LIBSBML_CPP_NAMESPACE_BEGIN

BEGIN_C_DECLS


typedef enum
{
	  LayoutUnknownError                      = 6010100
  , LayoutNSUndeclared                      = 6010101 
  , LayoutElementNotInNs                    = 6010102
  , LayoutDuplicateComponentId              = 6010301
  , LayoutSIdSyntax                         = 6010302
  , LayoutAttributeRequiredMissing          = 6020101
  , LayoutAttributeRequiredMustBeBoolean    = 6020102
  , LayoutRequiredFalse                     = 6020103
  , LayoutOnlyOneLOLayouts                  = 6020201
  , LayoutLOLayoutsNotEmpty                 = 6020202
  , LayoutLOLayoutsAllowedElements          = 6020203
  , LayoutLOLayoutsAllowedAttributes        = 6020204
  , LayoutLayoutAllowedElements             = 6020301
  , LayoutLayoutAllowedCoreAttributes       = 6020302
  , LayoutOnlyOneEachListOf                 = 6020303
  , LayoutNoEmptyListOfs                    = 6020304
  , LayoutLayoutAllowedAttributes           = 6020305
  , LayoutLayoutNameMustBeString            = 6020306
  , LayoutLOCompGlyphAllowedAttributes      = 6020307
  , LayoutLOCompGlyphAllowedElements        = 6020308
  , LayoutLOSpeciesGlyphAllowedAttributes   = 6020309
  , LayoutLOSpeciesGlyphAllowedElements     = 6020310
  , LayoutLORnGlyphAllowedAttributes        = 6020311
  , LayoutLORnGlyphAllowedElements          = 6020312
  , LayoutLOAddGOAllowedAttribut            = 6020313
  , LayoutLOAddGOAllowedElements            = 6020314
  , LayoutLayoutMustHaveDimensions          = 6020315
  , LayoutLOTextGlyphAllowedAttributes      = 6020316
  , LayoutLOTextGlyphAllowedElements        = 6020317
  , LayoutGOAllowedCoreElements             = 6020401
  , LayoutGOAllowedCoreAttributes           = 6020402
  , LayoutGOAllowedElements                 = 6020403
  , LayoutGOAllowedAttributes               = 6020404
  , LayoutGOMetaIdRefMustBeIDREF            = 6020405
  , LayoutGOMetaIdRefMustReferenceObject    = 6020406
  , LayoutGOMustContainBoundingBox          = 6020407
  , LayoutCGAllowedCoreElements             = 6020501
  , LayoutCGAllowedCoreAttributes           = 6020502
  , LayoutCGAllowedElements                 = 6020503
  , LayoutCGAllowedAttributes               = 6020504
  , LayoutCGMetaIdRefMustBeIDREF            = 6020505
  , LayoutCGMetaIdRefMustReferenceObject    = 6020506
  , LayoutCGCompartmentSyntax               = 6020507
  , LayoutCGCompartmentMustRefComp          = 6020508
  , LayoutCGNoDuplicateReferences           = 6020509
  , LayoutCGOrderMustBeDouble               = 6020510
  , LayoutSGAllowedCoreElements             = 6020601
  , LayoutSGAllowedCoreAttributes           = 6020602
  , LayoutSGAllowedElements                 = 6020603
  , LayoutSGAllowedAttributes               = 6020604
  , LayoutSGMetaIdRefMustBeIDREF            = 6020605
  , LayoutSGMetaIdRefMustReferenceObject    = 6020606
  , LayoutSGSpeciesSyntax                   = 6020607
  , LayoutSGSpeciesMustRefSpecies           = 6020608
  , LayoutSGNoDuplicateReferences           = 6020609
  , LayoutRGAllowedCoreElements             = 6020701
  , LayoutRGAllowedCoreAttributes           = 6020702
  , LayoutRGAllowedElements                 = 6020703
  , LayoutRGAllowedAttributes               = 6020704
  , LayoutRGMetaIdRefMustBeIDREF            = 6020705
  , LayoutRGMetaIdRefMustReferenceObject    = 6020706
  , LayoutRGReactionSyntax                  = 6020707
  , LayoutRGReactionMustRefReaction         = 6020708
  , LayoutRGNoDuplicateReferences           = 6020709
  , LayoutLOSpeciesRefGlyphAllowedElements  = 6020710
  , LayoutLOSpeciesRefGlyphAllowedAttribs   = 6020711
  , LayoutGGAllowedCoreElements             = 6020801
  , LayoutGGAllowedCoreAttributes           = 6020802
  , LayoutGGAllowedElements                 = 6020803
  , LayoutGGAllowedAttributes               = 6020804
  , LayoutGGMetaIdRefMustBeIDREF            = 6020805
  , LayoutGGMetaIdRefMustReferenceObject    = 6020806
  , LayoutGGReferenceSyntax                 = 6020807
  , LayoutGGReferenceMustRefObject          = 6020808
  , LayoutGGNoDuplicateReferences           = 6020809
  , LayoutLOReferenceGlyphAllowedElements   = 6020810
  , LayoutLOReferenceGlyphAllowedAttribs    = 6020811
  , LayoutLOSubGlyphAllowedElements         = 6020812
  , LayoutLOSubGlyphAllowedAttribs          = 6020813
  , LayoutTGAllowedCoreElements             = 6020901
  , LayoutTGAllowedCoreAttributes           = 6020902
  , LayoutTGAllowedElements                 = 6020903
  , LayoutTGAllowedAttributes               = 6020904
  , LayoutTGMetaIdRefMustBeIDREF            = 6020905
  , LayoutTGMetaIdRefMustReferenceObject    = 6020906
  , LayoutTGOriginOfTextSyntax              = 6020907
  , LayoutTGOriginOfTextMustRefObject       = 6020908
  , LayoutTGNoDuplicateReferences           = 6020909
  , LayoutTGGraphicalObjectSyntax           = 6020910
  , LayoutTGGraphicalObjectMustRefObject    = 6020911
  , LayoutTGTextMustBeString                = 6020912
  , LayoutSRGAllowedCoreElements            = 6021001
  , LayoutSRGAllowedCoreAttributes          = 6021002
  , LayoutSRGAllowedElements                = 6021003
  , LayoutSRGAllowedAttributes              = 6021004
  , LayoutSRGMetaIdRefMustBeIDREF           = 6021005
  , LayoutSRGMetaIdRefMustReferenceObject   = 6021006
  , LayoutSRGSpeciesReferenceSyntax         = 6021007
  , LayoutSRGSpeciesRefMustRefObject        = 6021008
  , LayoutSRGNoDuplicateReferences          = 6021009
  , LayoutSRGSpeciesGlyphSyntax             = 6021010
  , LayoutSRGSpeciesGlyphMustRefObject      = 6021011
  , LayoutSRGRoleSyntax                     = 6021012
  , LayoutSRGRoleMustBeSRGRoleValue         = 6021013
  , LayoutREFGAllowedCoreElements           = 6021101
  , LayoutREFGAllowedCoreAttributes         = 6021102
  , LayoutREFGAllowedElements               = 6021103
  , LayoutREFGAllowedAttributes             = 6021104
  , LayoutREFGMetaIdRefMustBeIDREF          = 6021105
  , LayoutREFGMetaIdRefMustReferenceObject  = 6021106
  , LayoutREFGReferenceSyntax               = 6021107
  , LayoutREFGReferenceMustRefObject        = 6021108
  , LayoutREFGNoDuplicateReferences         = 6021109
  , LayoutREFGGlyphSyntax                   = 6021110
  , LayoutREFGGlyphMustRefObject            = 6021111
  , LayoutREFGRoleSyntax                    = 6021112

  , LayoutPointAllowedCoreElements          = 6021201
  , LayoutPointAllowedCoreAttributes        = 6021202
  , LayoutPointAllowedAttributes            = 6021203
  , LayoutPointAttributesMustBeDouble       = 6021204

  , LayoutBBoxAllowedCoreElements           = 6021301
  , LayoutBBoxAllowedCoreAttributes         = 6021302
  , LayoutBBoxAllowedElements               = 6021303
  , LayoutBBoxAllowedAttributes             = 6021304
  , LayoutBBoxConsistent3DDefinition        = 6021305

  , LayoutCurveAllowedCoreElements          = 6021401
  , LayoutCurveAllowedCoreAttributes        = 6021402
  , LayoutCurveAllowedElements              = 6021403
  , LayoutCurveAllowedAttributes            = 6021404
  , LayoutLOCurveSegsAllowedAttributes      = 6021405
  , LayoutLOCurveSegsAllowedElements        = 6021406
  , LayoutLOCurveSegsNotEmpty               = 6021407

  , LayoutLSegAllowedCoreElements           = 6021501
  , LayoutLSegAllowedCoreAttributes         = 6021502
  , LayoutLSegAllowedElements               = 6021503
  , LayoutLSegAllowedAttributes             = 6021504
  , LayoutLSegTypeSyntax                    = 6021505
  , LayoutLSegTypeMustBeLineSegment         = 6021506

  , LayoutCBezAllowedCoreElements           = 6021601
  , LayoutCBezAllowedCoreAttributes         = 6021602
  , LayoutCBezAllowedElements               = 6021603
  , LayoutCBezAllowedAttributes             = 6021604
  , LayoutCBezTypeSyntax                    = 6021605
  , LayoutCBezTypeMustBeCubicBezier         = 6021606

  , LayoutDimsAllowedCoreElements           = 6021701
  , LayoutDimsAllowedCoreAttributes         = 6021702
  , LayoutDimsAllowedAttributes             = 6021703
  , LayoutDimsAttributesMustBeDouble        = 6021704

}  LayoutSBMLErrorCode_t;

END_C_DECLS

LIBSBML_CPP_NAMESPACE_END

#endif  /*  LayoutSBMLError_h__  */
