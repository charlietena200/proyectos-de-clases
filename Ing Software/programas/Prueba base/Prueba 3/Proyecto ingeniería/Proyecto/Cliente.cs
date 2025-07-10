using System;
using System.Collections.Generic;
using System.Text;

namespace Proyecto
{
    public class Cliente : Persona
    {
        private DateTime fechaRegistro;
        private int noCliente;
        private int noHabitacion;
        public Cliente(int noCliente, string nombre, string apPat, string apMat, int edad, string telefono, string direccion, int noHabitacion) : base(nombre, apPat, apMat, edad, telefono, direccion)
        {
            this.fechaRegistro = DateTime.Now;
            this.noCliente = noCliente;
            this.noHabitacion = noHabitacion;
        }
        public DateTime FechaRegistro
        {
            get { return fechaRegistro; }
        }
        public int NoCliente
        {
            get { return noCliente; }
        }
        public int NoHabitacion
        {
            get { return noHabitacion; }
        }
        public override string ToString()
        {
            return string.Format($"{base.ToString()}\nFecha registro: {fechaRegistro}\nNumero de cliente: {noCliente}\nNumero de habitacion: {noHabitacion}");
        }
    }
}
