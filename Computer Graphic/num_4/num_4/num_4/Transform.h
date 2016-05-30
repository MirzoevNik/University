value struct TPoint
{
	float x, y;
};

value struct TLine
{
	TPoint start, end;
	System::String^ name;
};

#define M 3
typedef float Vec[M];
typedef float Mat[M][M];

extern Mat T;

void times( Mat a, Mat b, Mat c ); // умножение матрицы на матрицу
void timesMatVec( Mat a, Vec b, Vec c ); // умножение матрицы на вектор
void set( Mat a, Mat b ); // перенос из матрицы в матрицу
void point2vec( TPoint a, Vec b ); // преобразование точки в вектор
void vec2point( Vec a, TPoint &b ); // преобразование вектора в точку
void makeHomogenVec( float x, float y, Vec c ); // преобразование координат в вектор
void unit( Mat a ); // преобразование исходной матрицы в единичную
void move( float t_x, float t_y, Mat c ); // матрица преобразования переноса
void rotate( float centre_x, float centre_y, float phi, Mat c ); // матрица преобразования поворота
void scale( float s_x, float s_y, Mat c ); // матрица преобразования масштабирования
void reflectVertical( Mat a ); // матрица преобразований отражения по вертикали
void reflectHorizontal( Mat a ); // матрица преобразований отражения по горизонтали
void frame( float v_x, float v_y, float v_cx, float v_cy, 
	float w_x, float w_y, float w_cx, float w_cy, 
	Mat c ); // матрица преобразований координат рамки из картинной СК в экранную СК
