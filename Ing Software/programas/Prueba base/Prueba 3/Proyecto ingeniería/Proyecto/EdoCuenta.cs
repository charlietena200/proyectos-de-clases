using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace Proyecto
{
    public class EdoCuenta
    {
        private string folio;
        private DateTime fechaEmision;
        private Cliente uH;
        private decimal subTotal;
        private decimal iva;
        private decimal total;
        private ArrayList listaConsumos;
        public EdoCuenta(string folio, Cliente uH)
        {
            this.folio = folio;
            this.uH = uH;
            fechaEmision = DateTime.Now;
            listaConsumos = new ArrayList();
            subTotal = 0;
            iva = 0.16M;
            total = 0;
        }
        public EdoCuenta(string folio, Cliente uH, ArrayList lista)
        {
            this.folio = folio;
            this.uH = uH;
            fechaEmision = DateTime.Now;
            listaConsumos = new ArrayList();
            subTotal = 0;
            iva = 0.16M;
            total = 0;
            listaConsumos = lista;
            foreach(Consumos a in listaConsumos)
            {
                subTotal += a.Precio;
                total = subTotal + (subTotal * iva);
            }
        }
        public string Folio
        {
            get { return folio; }
        }
        public DateTime FechaEmision
        {
            get { return fechaEmision; }
        }
        public decimal SubTotal
        {
            get { return subTotal; }
        }
        public decimal Iva
        {
            get { return iva; }
        }
        public decimal Total
        {
            get { return total; }
        }
        public string Nombre
        {
            get { return uH.Nombre; }
        }
        public string ApPat
        {
            get { return uH.ApPat; }
        }
        public string ApMat
        {
            get { return uH.ApMat; }
        }
        public int Edad
        {
            get { return uH.Edad; }
        }
        public string Telefono
        {
            get { return uH.Telefono; }
        }
        public string Direccion
        {
            get { return uH.Direccion; }
        }
        public DateTime FechaRegistro
        {
            get { return uH.FechaRegistro; }
        }
        public int NoCliente
        {
            get { return uH.NoCliente; }
        }
        public int NoHabitacion
        {
            get { return uH.NoHabitacion; }
        }
        public void agregarServicio(Consumos dato)
        {
            listaConsumos.Add(dato);
            subTotal += dato.Precio;
            total = subTotal + (subTotal * iva);
        }
        public int getLen()
        {

            return listaConsumos.Count;
        }
        public Consumos getDatosConsumo(Consumos x, int i)
        {
            x = (Consumos) listaConsumos[i];
            return x;
        }
        public override string ToString()
        {
            return string.Format($"\nFolio: {folio}\nFecha de emision: {fechaEmision}\n{uH.ToString()}\nSub Total: {subTotal}\nIVA: {iva}\nTotal: {total}");
        }
    }
}
