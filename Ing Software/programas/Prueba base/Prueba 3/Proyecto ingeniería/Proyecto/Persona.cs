using System;
using System.Collections.Generic;
using System.Text;

namespace Proyecto
{
    public class Persona
    {
        protected string nombre;
        protected string apPat;
        protected string apMat;
        protected int edad;
        protected string telefono;
        protected string direccion;
        public Persona(string nombre, string apPat, string apMat, int edad, string telefono, string direccion)
        {
            this.nombre = nombre;
            this.apMat = apMat;
            this.apPat = apPat;
            this.edad = edad;
            this.telefono = telefono;
            this.direccion = direccion;
        }
        public string Nombre
        {
            get { return nombre; }
        }
        public string ApPat
        {
            get { return apPat; }
        }
        public string ApMat
        {
            get { return apMat; }
        }
        public int Edad
        {
            get { return edad; }
        }
        public string Telefono
        {
            get { return telefono; }
        }
        public string Direccion
        {
            get { return direccion; }
        }
        public override string ToString()
        {
            return String.Format($"\nNombre: {nombre}\nApellido paterno: {apPat}\nApellido materno: {apMat}\nEdad: {edad}\nTelefono: {telefono}\nDireccion: {direccion}");
        }
    }
}
