/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkMRMLLabelMapVolumeDisplayNode.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/

#ifndef __vtkMRMLLabelMapVolumeDisplayNode_h
#define __vtkMRMLLabelMapVolumeDisplayNode_h

#include "vtkMRMLVolumeDisplayNode.h"

class vtkImageAlgorithm;
class vtkImageMapToColors;

/// \brief MRML node for representing a volume display attributes.
///
/// vtkMRMLLabelMapVolumeDisplayNode nodes describe how volume is displayed.
class VTK_MRML_EXPORT vtkMRMLLabelMapVolumeDisplayNode : public vtkMRMLVolumeDisplayNode
{
  public:
  static vtkMRMLLabelMapVolumeDisplayNode *New();
  vtkTypeMacro(vtkMRMLLabelMapVolumeDisplayNode,vtkMRMLVolumeDisplayNode);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  virtual vtkMRMLNode* CreateNodeInstance() VTK_OVERRIDE;

  ///
  /// Get node XML tag name (like Volume, Model)
  virtual const char* GetNodeTagName() VTK_OVERRIDE {return "LabelMapVolumeDisplay";}

  ///
  /// alternative method to propagate events generated in Display nodes
  virtual void ProcessMRMLEvents ( vtkObject * /*caller*/,
                                   unsigned long /*event*/,
                                   void * /*callData*/ ) VTK_OVERRIDE;
  ///
  /// set default labels colormap
  virtual void SetDefaultColorMap() VTK_OVERRIDE;

  /// Set the pipeline input
  virtual void SetInputImageDataConnection(vtkAlgorithmOutput *imageDataConnection) VTK_OVERRIDE;

  /// Get the pipeline input
  virtual vtkImageData* GetInputImageData() VTK_OVERRIDE;

  /// Gets the pipeline output
  virtual vtkAlgorithmOutput* GetOutputImageDataConnection() VTK_OVERRIDE;

  virtual void UpdateImageDataPipeline() VTK_OVERRIDE;

protected:
  vtkMRMLLabelMapVolumeDisplayNode();
  virtual ~vtkMRMLLabelMapVolumeDisplayNode();
  vtkMRMLLabelMapVolumeDisplayNode(const vtkMRMLLabelMapVolumeDisplayNode&);
  void operator=(const vtkMRMLLabelMapVolumeDisplayNode&);

  vtkImageMapToColors *MapToColors;

};

#endif
