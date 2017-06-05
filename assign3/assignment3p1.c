/*
 ============================================================================
 Date		 : 10/02/2015
 Assignment	 : Assignment 3 Part 1
 Description : This program outputs onto the console the volume and surface areas of
 	 	 	   circles, spheres, cylinders, and cones.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float circleArea (float r){
	return M_PI*r*r;
}

float circlePerimeter (float r){
	return M_PI*(r+r);
}

float sphereVolume (float r){
	float volume = M_PI*(r*r*r)*4/3;
	return volume;
}

float sphereSurfaceArea (float r) {
	return M_PI*4*(r*r);
}

float cylinderVolume (float r, float h){
	float baseArea = circleArea(r);
	float volume = h*baseArea;
	return  volume;
}

float cylinderSurfaceArea (float r, float h){
	float circles = 2*circleArea(r);
	float tube = h*circlePerimeter(r);
	float surfaceArea = tube + circles;
	return	surfaceArea;
}

float coneVolume (float r, float h){
	float baseArea = circleArea(r);
	float volume = (h/3)*baseArea;
	return volume;
}

float coneSurfaceArea (float r, float h){
	float base = circleArea(r);
	float l = sqrt(h*h+r*r);
	float point = M_PI*r*l;
	float area = point+base;
	return area;
}

int main(void) {
	float radius = 6.2;
	float height = 8.1;
	float c_area = circleArea(radius);
	float sphere_volume = sphereVolume(radius);
	float sphere_surface = sphereSurfaceArea(radius);
	float cylinder_volume = cylinderVolume(radius,height);
	float cylinder_surface = cylinderSurfaceArea(radius, height);
	float cone_volume = coneVolume(radius,height);
	float cone_surface = coneSurfaceArea(radius,height);
	float sum_volume = sphere_volume+cylinder_volume+cone_volume;
	float sum_area = sphere_surface+cylinder_surface+cone_surface+c_area;

	printf("Circle:    Radius = %1.1f\t\t\t\t      Area = %3.1f\n",radius, c_area);
	printf("Sphere:    Radius = %1.1f\t\t     Volume = %3.1f   Area = %3.1f\n",radius,sphere_volume,sphere_surface);
	printf("Cylinder:  Radius = %1.1f Height = %1.1f Volume = %3.1f   Area = %3.1f\n",radius,height,cylinder_volume,cylinder_surface);
	printf("Cone:      Radius = %1.1f Height = %1.1f Volume = %3.1f   Area = %3.1f\n",radius, height, cone_volume,cone_surface);
	printf("sum:\t\t\t\t     Volumes = %4.1f Areas= %4.1f",sum_volume,sum_area);

	return EXIT_SUCCESS;
}
