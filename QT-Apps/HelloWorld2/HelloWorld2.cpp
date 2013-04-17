#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	QLabel *label = new QLabel("<h2>Hello World!<h2><b><font color=green>Qt supports HTML formatting!</font>");
	label->show();
	return app.exec();
}

