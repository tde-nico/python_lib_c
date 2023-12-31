#include <Python.h>

int	CfindPrimes(int num1, int num2)
{
	int flag_var;
	int	i;
	int	j;

	i = num1;
	printf("The Prime Numbers in (%d,%d) are:\n", num1, num2);
	while (++i < num2)
	{
		flag_var = 0;
		j = 1;
		while (++j <= (i / 2))
		{
			if ((i % j) == 0)
			{
				flag_var = 1;
				break ;
			}
		}
		if (flag_var == 0)
			printf("%d\n", i);
	}
	return (0);
}

static PyObject *findPrimes(PyObject *self, PyObject *args)
{
	int	num1;
	int	num2;
	int	sts;

	if (!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return (NULL);
	sts = CfindPrimes(num1, num2);
	return (PyLong_FromLong(sts));
}

static PyObject *version(PyObject *self)
{
	return (Py_BuildValue("s", "Version 0.01"));
}

static PyMethodDef Modules[] = {
	{"findPrimes", findPrimes, METH_VARARGS, "Calculates and prints all prime numbers between lower bound and upper bound provided by given range"},
	{"version", (PyCFunction)version, METH_NOARGS, "returns the version of the module"},
	{NULL, NULL, 0, NULL},
};

static struct PyModuleDef Module = {
	PyModuleDef_HEAD_INIT,
	"Module",
	"findPrimes Module",
	-1, // global state
	Modules,
};

// INITIALIZER FUNCTION
PyMODINIT_FUNC PyInit_Module(void)
{
	return (PyModule_Create(&Module));
}
