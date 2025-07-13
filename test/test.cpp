#include "test.h"

TEST(Controller, getVertexes) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::Vertex v(2.0, 2.0, 2.0);
  const s21::Vertex &t_v = controller.getVertexes()[7];
  EXPECT_EQ(t_v.x(), v.x());
  EXPECT_EQ(t_v.y(), v.y());
  EXPECT_EQ(t_v.z(), v.z());
}

TEST(Controller, getFaces) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  vector<int> v;
  v.push_back(1);
  v.push_back(7);
  v.push_back(5);
  const auto &t_v = controller.getFaces();
  EXPECT_EQ(t_v[0].getFaceMembers(), v);
}

TEST(Controller, parseModel_1) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  EXPECT_EQ(controller.getVertexes()[0].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].z(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].z(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[2].y(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].z(), 0.0);
}

TEST(Controller, parseModel_2) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  EXPECT_EQ(controller.getFaces()[0].getFaceMembers()[0], 1);
  EXPECT_EQ(controller.getFaces()[0].getFaceMembers()[1], 7);
  EXPECT_EQ(controller.getFaces()[0].getFaceMembers()[2], 5);
}

TEST(Controller, parseModel_3) {
  s21::Controller controller;
  EXPECT_ANY_THROW(controller.parseModel("obj_files/throw_1.obj"));
}

TEST(Controller, parseModel_4) {
  s21::Controller controller;
  EXPECT_ANY_THROW(controller.parseModel("obj_files/throw_2.obj"));
}

TEST(Controller, getVertexNum) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  EXPECT_EQ(controller.getVertexNum(), 8);
}

TEST(Controller, getEdgeNum) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  EXPECT_EQ(controller.getEdgeNum(), 17);
}

TEST(Controller, normalizeModel) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::Scale s;
  controller.normalizeModel(&s);
  EXPECT_EQ(controller.getVertexes()[0].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].z(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].z(), 1.8);
  EXPECT_EQ(controller.getVertexes()[2].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[2].y(), 1.8);
  EXPECT_EQ(controller.getVertexes()[2].z(), 0.0);
}

TEST(Controller, transform_RotateX) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::RotateX s;
  controller.transform(&s, 2.0);
  EXPECT_NEAR(controller.getVertexes()[0].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].y(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].z(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].y(), 0.069799, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].z(), 1.99878, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].y(), 1.99878, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].z(), -0.069799, 0.00001);
}

TEST(Controller, RotateY) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::RotateY s;
  s21::Model *m = s21::Model::mdGet();
  m->setAffine(&s);
  controller.transform(m->affine(), 2.0);
  EXPECT_NEAR(controller.getVertexes()[0].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].y(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].z(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].x(), 0.069799, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].y(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].z(), 1.99878, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].y(), 2.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].z(), 0.0, 0.00001);
}

TEST(Controller, RotateZ) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::RotateZ s;
  controller.transform(&s, 2.0);
  EXPECT_NEAR(controller.getVertexes()[0].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].y(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[0].z(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].x(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].y(), 0.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[1].z(), 2.0, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].x(), 0.069799, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].y(), 1.99878, 0.00001);
  EXPECT_NEAR(controller.getVertexes()[2].z(), 0.0, 0.00001);
}

TEST(Controller, TranslateX) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::TranslateX s;
  controller.transform(&s, 2.0);
  EXPECT_EQ(controller.getVertexes()[0].x(), 2.0);
  EXPECT_EQ(controller.getVertexes()[0].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].z(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].x(), 2.0);
  EXPECT_EQ(controller.getVertexes()[1].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].z(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].x(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].y(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].z(), 0.0);
}

TEST(Controller, TranslateY) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::TranslateY s;
  controller.transform(&s, 2.0);
  EXPECT_EQ(controller.getVertexes()[0].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].y(), 2.0);
  EXPECT_EQ(controller.getVertexes()[0].z(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].y(), 2.0);
  EXPECT_EQ(controller.getVertexes()[1].z(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[2].y(), 4.0);
  EXPECT_EQ(controller.getVertexes()[2].z(), 0.0);
}

TEST(Controller, TranslateZ) {
  s21::Controller controller;
  controller.parseModel("obj_files/cube.obj");
  s21::TranslateZ s;
  controller.transform(&s, 2.0);
  EXPECT_EQ(controller.getVertexes()[0].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[0].z(), 2.0);
  EXPECT_EQ(controller.getVertexes()[1].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].y(), 0.0);
  EXPECT_EQ(controller.getVertexes()[1].z(), 4.0);
  EXPECT_EQ(controller.getVertexes()[2].x(), 0.0);
  EXPECT_EQ(controller.getVertexes()[2].y(), 2.0);
  EXPECT_EQ(controller.getVertexes()[2].z(), 2.0);
}

TEST(Action, Constructor) {
  s21::Action a;
  EXPECT_TRUE(a.rx_ != nullptr);
  EXPECT_TRUE(a.ry_ != nullptr);
  EXPECT_TRUE(a.rz_ != nullptr);
  EXPECT_TRUE(a.s_ != nullptr);
  EXPECT_TRUE(a.tx_ != nullptr);
  EXPECT_TRUE(a.ty_ != nullptr);
  EXPECT_TRUE(a.tz_ != nullptr);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}