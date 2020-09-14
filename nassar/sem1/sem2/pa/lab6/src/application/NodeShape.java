package application;

import java.awt.geom.Ellipse2D;

public class NodeShape extends Ellipse2D.Double {
	public NodeShape(double x0, double y0, double radius) {
	super(x0 - radius / 2, y0 - radius / 2, radius, radius);
	}
}


/*
Ellipse2D.Double also implements Shape
 Take a look at Shape interface and its implementations:
	Arc2D, Arc2D.Double, Arc2D.Float, Area, BasicTextUI.BasicCaret, CubicCurve2D, CubicCurve2D.Double,
	CubicCurve2D.Float, DefaultCaret, Ellipse2D, Ellipse2D.Double, Ellipse2D.Float, GeneralPath,
	Line2D, Line2D.Double, Line2D.Float, Path2D, Path2D.Double, Path2D.Float, Polygon, QuadCurve2D,
	QuadCurve2D.Double, QuadCurve2D.Float, Rectangle, Rectangle2D, Rectangle2D.Double,
	Rectangle2D.Float, RectangularShape, RoundRectangle2D, RoundRectangle2D.Double,
	RoundRectangle2D.Float
	 You may create a custom Shape implementation (bonus!)

*/