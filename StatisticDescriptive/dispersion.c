
#include "statistic_descriptive.h"

// Variation
/*
 * Variation = xi - Av
 *
 */

void variation (double *vector_data, double *vector_freq, double *vector_variation, int lenght) { // Require average_ari_pond

	int i; // For Loop Variable
	double Av; // Average Of Vector_Data's Elements

	Av = average_ari_pond (vector_data,vector_freq,lenght);

	for (i=0; i<lenght; i++) { vector_variation[i] = vector_data[i] - Av; }

}



// Variance
/*
 * Variance = sum(variation(i)*variation(i)*freq(i))
 *
 */

double variance (double *vector_data, double *vector_freq, int lenght) { // Require vector_vector_mult && vector_el_sum && variation

	double vector_variation[lenght]; // variation[i]
	double vector_variation_quad[lenght]; // variation[i]*variation[i]
	double vector_result[lenght]; // variation[i]*variation[i]*freq[i]
	double result;

	variation (vector_data,vector_freq,vector_variation,lenght); // Vector Variation Calculation

	vector_vector_mult (vector_variation,vector_variation,vector_variation_quad,lenght); // Vector Variation*Variation Calculation

	vector_vector_mult (vector_variation_quad,vector_freq,vector_result,lenght); // Vector Variation*Variation*Freq Calculation

	result = vector_el_sum (vector_result,lenght); // Sum Vector Result Elements

	return result;

}



// Standard Deviation
/*
 * Sd = sqrt(variance)
 *
 */

double standard_deviation (double *vector_data, double *vector_freq, int lenght) { // Require variance

	double result;

	result = sqrt (variance (vector_data,vector_freq,lenght));

	return result;

}

