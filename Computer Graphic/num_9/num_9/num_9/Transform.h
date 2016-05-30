#include <array>
#include <vector>

value struct TPoint
{
	float x, y;
};

value struct TLine
{
	TPoint start, end;
	System::String^ name;
};

value struct Point3D
{
	float x, y, z;
};

typedef System::Collections::Generic::List< TPoint > Polygon;
typedef System::Collections::Generic::List< Point3D > Polygon3D;

#define M 3
typedef std::tr1::array< float, M > Vec;
typedef std::tr1::array< Vec, M > Mat;

#define M3D 4
typedef std::tr1::array< float, M3D > Vec3D;
typedef std::tr1::array< Vec3D, M3D > Mat3D;

extern Mat T;
extern std::vector< Mat > matrices;

extern Mat3D T3D;

void times( Mat a, Mat b, Mat &c ); // умножение матрицы на матрицу
void timesMatVec( Mat a, Vec b, Vec &c ); // умножение матрицы на вектор
void set( Mat a, Mat &b ); // перенос из матрицы в матрицу
void point2vec( TPoint a, Vec &b ); // преобразование точки в вектор
void vec2point( Vec a, TPoint &b ); // преобразование вектора в точку
void makeHomogenVec( float x, float y, Vec &c ); // преобразование координат в вектор
void unit( Mat &a ); // преобразование исходной матрицы в единичную
void move( float t_x, float t_y, Mat &c ); // матрица преобразования переноса
void rotate( float centre_x, float centre_y, float phi, Mat &c ); // матрица преобразования поворота
void rotate( float phi, Mat &c );
void scale( float s_x, float s_y, Mat &c ); // матрица преобразования масштабирования
void reflectVertical( Mat &a ); // матрица преобразований отражения по вертикали
void reflectHorizontal( Mat &a ); // матрица преобразований отражения по горизонтали
void frame( float v_x, float v_y, float v_cx, float v_cy, 
	float w_x, float w_y, float w_cx, float w_cy, 
	Mat &c ); // матрица преобразований координат рамки из картинной СК в экранную СК


void times( Mat3D a, Mat3D b, Mat3D &c );
void timesMatVec( Mat3D a, Vec3D b, Vec3D &c );
void set( Mat3D a, Mat3D &b );
void point2vec( Point3D a, Vec3D &b );
void vec2point( Vec3D a, Point3D &b );
void makeHomogenVec( float x, float y, float z, Vec3D &c );
void unit( Mat3D &a );
void move( float t_x, float t_y, float t_z, Mat3D &c );
void rotate( Point3D n, float phi, Mat3D &c );
void scale( float s_x, float s_y, float s_z, Mat3D &c );void lookAt( Point3D eye, Point3D center, Point3D up, Mat3D &c );void ortho( float v_x, float v_y, float near, float far, Mat3D &c );
void frustrum( float v_x, float v_y, float near, float far, Mat3D &c );
void perspective( float fovy, float aspect, float near, float far, Mat3D &c );void set( Point3D a, TPoint &b );void calcDirVects( Point3D eye, Point3D center, Point3D up, Vec3D &a, Vec3D &b, Vec3D &c );void normalize( Vec3D &a );void mult( Mat3D a, float koef, Mat3D &c );void mult( Vec3D a, float koef, Vec3D &c );void multVec( Vec3D a, Vec3D b, Vec3D &c );void sum( Mat3D a, Mat3D b, Mat3D &c );void sum( Vec3D a, Vec3D b, Vec3D &c );