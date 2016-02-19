typedef void* ImzbReader;
ImzbReader imzb_reader_new(char*);
void imzb_reader_free(ImzbReader);
int imzb_reader_height(ImzbReader);
int imzb_reader_width(ImzbReader);
void imzb_reader_image(ImzbReader, double mz, double ppm, float* out);

typedef void* IsotopePattern;
IsotopePattern isotope_pattern_new(int n, double* masses, double* abundances);
IsotopePattern isotope_pattern_new_from_sf(char* formula, double thr, double fft_thr);
double isotope_pattern_envelope(IsotopePattern, double resolution, double mz);
IsotopePattern isotope_pattern_centroids(IsotopePattern, double resolution, double min_abundance,
                                         int points_per_fwhm);
int isotope_pattern_size(IsotopePattern);
void isotope_pattern_masses(IsotopePattern, double*);
void isotope_pattern_abundances(IsotopePattern, double*);
void isotope_pattern_add_charge(IsotopePattern, int);
void isotope_pattern_trim(IsotopePattern, unsigned);
void isotope_pattern_free(IsotopePattern);

double measure_of_chaos_f(float* image, int width, int height, int n_levels);
double measure_of_chaos_d(double* image, int width, int height, int n_levels);

double iso_img_correlation_f(float** images, int n, int width, int height, IsotopePattern isotope_pattern);
double iso_img_correlation_d(double** images, int n, int width, int height, IsotopePattern isotope_pattern);

double pattern_match_f(float** images, int n, int width, int height, IsotopePattern isotope_pattern);
double pattern_match_d(double** images, int n, int width, int height, IsotopePattern isotope_pattern);
