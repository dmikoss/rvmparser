#pragma once
#include <cstdio>

#include "StoreVisitor.h"

class ExportObj : public StoreVisitor
{
public:
  ~ExportObj();

  bool open(const char* path_obj, const char* path_mtl);

  void init(class Store& store) override;

  void beginFile(const char* info, const char* note, const char* date, const char* user, const char* encoding) override;

  void endFile() override;

  void beginModel(const char* project, const char* name) override;

  void endModel() override;

  void beginGroup(struct Group* group) override;

  void EndGroup() override;

  void geometry(struct Geometry* geometry) override;

  void composite(struct Composite* comp) override;

private:
  FILE* out = nullptr;
  FILE* mtl = nullptr;
  unsigned off_v = 1;
  unsigned off_n = 1;
  struct Connectivity* conn = nullptr;
  float curr_translation[3] = { 0,0,0 };

  bool anchors = false;
  bool primitiveBoundingBoxes = false;
  bool compositeBoundingBoxes = false;

};